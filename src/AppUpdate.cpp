#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {
	if (m_LM->isInGame() && !m_LM->getIsEndGame()) {
		// the part deal with the player gravity
		if (m_Player->GetGravityFlipped()) {
			if (m_LM->isMoveAble(m_Player->GetPosition(), false, true) &&
				!fallAble && !m_LM->isStepOnQuickSand(m_Player->GetPosition()) &&
				m_LM->getCurrentPlatform() == nullptr) {
				m_Player->Update();
			}
			m_Player->SetFlipAble(!(m_LM->isMoveAble(m_Player->GetPosition(), false, true)) ||
				m_LM->isStepOnQuickSand(m_Player->GetPosition()) ||
				m_LM->getCurrentPlatform() != nullptr);
		}
		else {
			if (m_LM->isMoveAble(m_Player->GetPosition(), true, true) &&
				!fallAble && !m_LM->isStepOnQuickSand(m_Player->GetPosition()) &&
				m_LM->getCurrentPlatform() == nullptr) {
				m_Player->Update();
			}
			m_Player->SetFlipAble(!(m_LM->isMoveAble(m_Player->GetPosition(), true, true)) ||
				m_LM->isStepOnQuickSand(m_Player->GetPosition()) ||
				m_LM->getCurrentPlatform() != nullptr);
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
				if (m_LM->isMoveAble(m_Player->GetPosition(), false, false) && !m_LM->IsTouchQuickSandRight(m_Player->GetPosition())) {
					m_Player->Move(false, 2);
				}
				else {
					break;
				}
			}
		}
		else if (Util::Input::IsKeyUp(Util::Keycode::LEFT) || Util::Input::IsKeyUp(Util::Keycode::A)) {
			for (int i = 4;i>0;i--) {
				if (m_LM->isMoveAble(m_Player->GetPosition(), false, false) && !m_LM->IsTouchQuickSandRight(m_Player->GetPosition())) {
					m_Player->Move(false, i);
				}
				else {
					break;
				}
			}
		}
		if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT) || Util::Input::IsKeyPressed(Util::Keycode::D)) {
			for (int i = 6;i>0;i--) {
				if (m_LM->isMoveAble(m_Player->GetPosition(), true, false) && !m_LM->IsTouchQuickSandLeft(m_Player->GetPosition())) {
					m_Player->Move(true, 2);
				}
				else {
					break;
				}
			}
		}
		else if (Util::Input::IsKeyUp(Util::Keycode::RIGHT) || Util::Input::IsKeyUp(Util::Keycode::D)) {
			for (int i = 4;i>0;i--) {
				if (m_LM->isMoveAble(m_Player->GetPosition(), true, false) && !m_LM->IsTouchQuickSandLeft(m_Player->GetPosition())) {
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
		if (Util::Input::IsKeyDown(Util::Keycode::K)) {
			m_LM->setPlayerCantKill();
		}

		// the part deal with the player touch the trap, enemy
		if ((m_LM->isTouchTrap(m_Player->GetPosition()) || m_LM->isTouchEnemy(m_Player->GetPosition())) && !m_LM->getPlayerCantKill()) {
			m_LM->addDeathCounter();
			m_Player->SetPosition(m_LM->getSavePointPosition());
			if (m_Player->GetGravityFlipped() != m_LM->getSavePointIsReverse()) {
				m_Player->FlipGravity();
			}
			if (m_LM->getCurrentLevelID() != m_LM->getSavePointLevelID()) {m_LM->setLevelDataByID(m_LM->getSavePointLevelID());}
		}

		// the part deal with the player touch the trinket
		m_LM->isTouchTrinket(m_Player->GetPosition());

		// the part deal with the player touch the save point
		if (m_LM->isTouchSavePoint(m_Player->GetPosition())) {
			m_LM->setSavePointPosition(m_Player->GetPosition());
		}

		// the part deal with the player touch the enemy
		m_LM->updateEnemies();

		// the part deal with the player touch the moving platform
		m_LM->updateMovingPlatforms(m_Player->GetPosition());

		// the part deal with the player step on moving platform
		if (m_LM->getCurrentPlatform() != nullptr) {
			MovingPlatform* platform = m_LM->getCurrentPlatform();

			if (platform->GetVertical())
			{
				if (platform->GetIsIncrement())
					m_Player->MoveY(true, platform->GetSpeed());
				else
					m_Player->MoveY(false, platform->GetSpeed());
			}
			else
			{
				if (platform->GetIsIncrement())
					m_Player->Move(true, platform->GetSpeed());
				else
					m_Player->Move(false, platform->GetSpeed());
			}
		}

		// the part deal with the player end game
		if (m_LM->getCurrentLevelID() == LevelID::AWrinkleInTime && (Util::Input::IsKeyDown(Util::Keycode::RETURN) || Util::Input::IsKeyDown(Util::Keycode::KP_ENTER))) {
			m_LM->setIsinGame(false);
			m_LM->setIsEndGame();
		}
	}

	// the part deal with the player call the map
	if ((Util::Input::IsKeyDown(Util::Keycode::RETURN) || Util::Input::IsKeyDown(Util::Keycode::KP_ENTER)) && !m_LM->getIsEndGame()) {
		if (m_Map->isMapCalled()) {
			m_Map->setMapCalled(false);
		}
		else {
			m_Map->setMapCalled(true);
			m_LM->setIsinGame(false);
		}
		m_Map->setMapMoveComplete(false);
		m_Map->updatePage();
		m_Map->updateStats(m_LM->getDeathCounter(), m_LM->getTrinketCount());
	}
	if (m_Map->isMapCalled() == true && !m_Map->isMapMoveComplete()) {
		m_Map->callMap();
	}
	else if (m_Map->isMapCalled() == true && m_Map->isMapMoveComplete()) {
		if (Util::Input::IsKeyDown(Util::Keycode::LEFT) || Util::Input::IsKeyDown(Util::Keycode::A)) {
			m_Map->PreviousPage();
		}
		else if (Util::Input::IsKeyDown(Util::Keycode::RIGHT) || Util::Input::IsKeyDown(Util::Keycode::D)) {
			m_Map->NextPage();
		}
	}
	else if (m_Map->isMapCalled() == false && !m_Map->isMapMoveComplete()) {
		m_Map->returnMap();
	}
	else if (m_Map->isMapMoveComplete() && !m_Map->isMapCalled()) { m_LM->setIsinGame(true); }

	m_Map->addTime();

	// the part deal with the player end game
	if (m_LM->getIsEndGame()) {
        m_LM->endGame();
		if ((Util::Input::IsKeyDown(Util::Keycode::SPACE) ||
			Util::Input::IsKeyDown(Util::Keycode::UP) ||
			Util::Input::IsKeyDown(Util::Keycode::DOWN) ||
			Util::Input::IsKeyDown(Util::Keycode::W) ||
			Util::Input::IsKeyDown(Util::Keycode::S)) &&
			m_LM->getEndGameTimer() >= 60 * 3) {
			m_CurrentState = State::END;
		}
    }

	// the part deal with the game update
    m_Root.Update();
}
