#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {
	if (m_LM->isInGame()) {
		// the part deal with the player gravity
		if (m_Player->GetGravityFlipped()) {
			if (m_LM->isMoveAble(m_Player->GetPosition(), false, true) && !fallAble && !m_LM->isSteppedOnQuickSand()) {
				m_Player->Update();
			}
			m_Player->SetFlipAble(!(m_LM->isMoveAble(m_Player->GetPosition(), false, true)));
		}
		else {
			if (m_LM->isMoveAble(m_Player->GetPosition(), true, true) && !fallAble && !m_LM->isSteppedOnQuickSand()) {
				m_Player->Update();
			}
			m_Player->SetFlipAble(!(m_LM->isMoveAble(m_Player->GetPosition(), true, true)));
		}

		// the part deal with the player touch the wall
		if (m_Player->isTouchUpWall()) {
			m_LM->isTouchUpWall();
			m_Map->mapVisited(static_cast<int>(m_LM->getCurrentLevelID()));
			m_Map->mapCurrent(static_cast<int>(m_LM->getCurrentLevelID()));
		}
		if (m_Player->isTouchDownWall()) {
			m_LM->isTouchDownWall();
			m_Map->mapVisited(static_cast<int>(m_LM->getCurrentLevelID()));
			m_Map->mapCurrent(static_cast<int>(m_LM->getCurrentLevelID()));
		}
		if (m_Player->isTouchLeftWall()) {
			m_LM->isTouchLeftWall();
			m_Player->Move(false);
			m_Map->mapVisited(static_cast<int>(m_LM->getCurrentLevelID()));
			m_Map->mapCurrent(static_cast<int>(m_LM->getCurrentLevelID()));
		}
		if (m_Player->isTouchRightWall()) {
			m_LM->isTouchRightWall();
			m_Player->Move(true);
			m_Map->mapVisited(static_cast<int>(m_LM->getCurrentLevelID()));
			m_Map->mapCurrent(static_cast<int>(m_LM->getCurrentLevelID()));
		}

		// the part deal with the player flip gravity
		if ((Util::Input::IsKeyDown(Util::Keycode::SPACE) ||
			Util::Input::IsKeyDown(Util::Keycode::UP) ||
			Util::Input::IsKeyDown(Util::Keycode::DOWN) ||
			Util::Input::IsKeyDown(Util::Keycode::W) ||
			Util::Input::IsKeyDown(Util::Keycode::S)) &&
			m_Player->GetFlipAble() ) {
			m_Player->FlipGravity();
			m_Player->Update();
		}

		// the part deal with the player move
		if (Util::Input::IsKeyPressed(Util::Keycode::LEFT) || Util::Input::IsKeyPressed(Util::Keycode::A)) {
			for (int i = 6;i>0;i--) {
				if (m_LM->isMoveAble(m_Player->GetPosition(), false, false)) {
					m_Player->Move(false, 2);
				}
				else {
					break;
				}
			}
		}
		else if (Util::Input::IsKeyUp(Util::Keycode::LEFT) || Util::Input::IsKeyUp(Util::Keycode::A)) {
			for (int i = 4;i>0;i--) {
				if (m_LM->isMoveAble(m_Player->GetPosition(), false, false)) {
					m_Player->Move(false, i);
				}
				else {
					break;
				}
			}
		}
		if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT) || Util::Input::IsKeyPressed(Util::Keycode::D)) {
			// if (m_LM->isMoveAble(m_Player->GetPosition(), true, false)) {
			// 	m_Player->Move(true);
			// }
			for (int i = 6;i>0;i--) {
				if (m_LM->isMoveAble(m_Player->GetPosition(), true, false)) {
					m_Player->Move(true, 2);
				}
				else {
					break;
				}
			}
		}
		else if (Util::Input::IsKeyUp(Util::Keycode::RIGHT) || Util::Input::IsKeyUp(Util::Keycode::D)) {
			for (int i = 4;i>0;i--) {
				if (m_LM->isMoveAble(m_Player->GetPosition(), true, false)) {
					m_Player->Move(true, i);
				}
				else {
					break;
				}
			}
		}

		// the part deal with the player use cheat
		if (Util::Input::IsKeyDown(Util::Keycode::N)) {
			fallAble = !fallAble;
		}

		// the part deal with the player touch the trap, enemy
		if (m_LM->isTouchTrap(m_Player->GetPosition()) || m_LM->isTouchEnemy(m_Player->GetPosition())) {
			m_Player->SetPosition(m_LM->getSavePointPosition());
			if (m_Player->GetGravityFlipped() != m_LM->getSavePointIsReverse()) {
				m_Player->FlipGravity();
			}
			if (m_LM->getCurrentLevelID() != m_LM->getSavePointLevelID()) {m_LM->setLevelDataByID(m_LM->getSavePointLevelID());}
		}

		// the part deal with the player touch the save point
		if (m_LM->isTouchSavePoint(m_Player->GetPosition())) {
			m_LM->setSavePointPosition(m_Player->GetPosition());
		}

		// the part deal with the player touch the enemy
		m_LM->updateEnemies();
	}

	// the part deal with the player call the map
	if (Util::Input::IsKeyDown(Util::Keycode::M)) {
		if (m_Map->isMapCalled()) {
			m_Map->setMapCalled(false);
		}
		else {
			m_Map->setMapCalled(true);
			m_LM->setIsinGame(false);
		}
		m_Map->setMapMoveComplete(false);
		m_Map->updateMap();
	}
	if (m_Map->isMapCalled() == true && !m_Map->isMapMoveComplete()) {
		m_Map->callMap();
	}
	else if (m_Map->isMapCalled() == false && !m_Map->isMapMoveComplete()) {
		m_Map->returnMap();
	}
	else if (m_Map->isMapMoveComplete() && !m_Map->isMapCalled()) { m_LM->setIsinGame(true); }

	// the part deal with the game update
    m_Root.Update();
}
