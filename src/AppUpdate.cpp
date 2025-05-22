#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

	if (m_Player->GetGravityFlipped()) {
		if (m_LM->isMoveAble(m_Player->GetPosition(), false, true) && !fallAble) {
			m_Player->Update();
		}
		m_Player->SetFlipAble(!(m_LM->isMoveAble(m_Player->GetPosition(), false, true)));
	}
	else {
		if (m_LM->isMoveAble(m_Player->GetPosition(), true, true) && !fallAble) {
			m_Player->Update();
		}
		m_Player->SetFlipAble(!(m_LM->isMoveAble(m_Player->GetPosition(), true, true)));
	}


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

	if ((Util::Input::IsKeyDown(Util::Keycode::SPACE) ||
		Util::Input::IsKeyDown(Util::Keycode::UP) ||
		Util::Input::IsKeyDown(Util::Keycode::DOWN) ||
		Util::Input::IsKeyDown(Util::Keycode::W) ||
		Util::Input::IsKeyDown(Util::Keycode::S)) &&
		m_Player->GetFlipAble() ) {
		m_Player->FlipGravity();
		m_Player->Update();
	}

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

	if (Util::Input::IsKeyDown(Util::Keycode::N)) {
		fallAble = !fallAble;
	}

	//if player is touching the trap or enemy
	if (m_LM->isTouchTrap(m_Player->GetPosition()) || m_LM->isTouchEnemy(m_Player->GetPosition())) {
		m_Player->SetPosition(m_LM->getSavePointPosition());
		if (m_Player->GetGravityFlipped() != m_LM->getSavePointIsReverse()) {
			m_Player->FlipGravity();
		}
		if (m_LM->getCurrentLevelID() != m_LM->getSavePointLevelID()) {m_LM->setLevelDataByID(m_LM->getSavePointLevelID());}
	}

	if (m_LM->isTouchSavePoint(m_Player->GetPosition())) {
		m_LM->setSavePointPosition(m_Player->GetPosition());
	}

	m_LM->updateEnemies();

	if (Util::Input::IsKeyDown(Util::Keycode::M)) {
		if (m_Map->isMapCalled()) {
			m_Map->setMapCalled(false);
		}
		else {
			m_Map->setMapCalled(true);
		}
		m_Map->setMapMoveComplete(false);
		m_Map->updateMap();
	}

	if (m_Map->isMapCalled() == true && m_Map->isMapMoveComplete() == false) {
		m_Map->callMap();
	}
	else if (m_Map->isMapCalled() == false && m_Map->isMapMoveComplete() == false) {
		m_Map->returnMap();
	}

    m_Root.Update();
}
