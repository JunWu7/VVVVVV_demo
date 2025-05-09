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
	}
	if (m_Player->isTouchDownWall()) {
		m_LM->isTouchDownWall();
	}
	if (m_Player->isTouchLeftWall()) {
		m_LM->isTouchLeftWall();
		m_Player->Move(false);
	}
	if (m_Player->isTouchRightWall()) {
		m_LM->isTouchRightWall();
		m_Player->Move(true);
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

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.

	if (Util::Input::IsKeyDown(Util::Keycode::UP)) {
		m_Giraffe->ChangePositionUp();
	}

	if (Util::Input::IsKeyDown(Util::Keycode::DOWN)) {
		m_Giraffe->ChangePositionDown();
	}

	if (Util::Input::IsKeyDown(Util::Keycode::LEFT)) {
		m_Giraffe->ChangePositionLeft();
	}

	if (Util::Input::IsKeyDown(Util::Keycode::RIGHT)) {
		m_Giraffe->ChangePositionRight();
	}

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

	if (m_Giraffe->IfCollides(m_Chest)) {
		m_Chest->SetVisible(false);
	}

	if (Util::Input::IsKeyPressed(Util::Keycode::P)) {
		m_Bee->SetLooping(true);
		m_Bee->SetPlaying(true);
		// m_Giraffe->ChangePositionLeft();
	}

	if (m_Doors[0]->GetVisibility()) {
		if (m_Giraffe->IfCollides(m_Doors[0])) {
			m_Doors[0]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
		}
	}

	if (m_Doors[1]->GetVisibility()) {
		if (m_Giraffe->IfCollides(m_Doors[1])) {
			m_Doors[1]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
		}
	}
	
	if (m_Doors[2]->GetVisibility()) {
		if (m_Giraffe->IfCollides(m_Doors[2])) {
			m_Doors[2]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
		}
	}

	if (Util::Input::IsKeyPressed(Util::Keycode::O)) {
		m_Ball->SetVisible(true);
		m_Ball->SetLooping(false);
		m_Ball->SetPlaying(true);
	}


    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);
	*/



    m_Root.Update();
}
