#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

	// if (abs(m_Player->GetPosition().y) < 487.5f) {
	// 	m_Player->Update();
	// }
	// else {
	// 	m_Player->ChangeFlipAble();
	// }

	m_Player->Update();
	m_Player->isTouchHeightWall();
	m_Player->isTouchWidthWall();

	if ((Util::Input::IsKeyDown(Util::Keycode::SPACE) ||Util::Input::IsKeyDown(Util::Keycode::UP) ||
		Util::Input::IsKeyDown(Util::Keycode::W)) && m_Player->GetFlipAble() ) {
		m_Player->FlipGravity();
		m_Player->Update();
		// m_Player->ChangeFlipAble();
	}

	if (Util::Input::IsKeyPressed(Util::Keycode::LEFT) || Util::Input::IsKeyPressed(Util::Keycode::A)) {
		m_Player->Move(false);
	}
	else if (Util::Input::IsKeyUp(Util::Keycode::LEFT) || Util::Input::IsKeyPressed(Util::Keycode::A)) {
		for (int i = 5;i>0;i--) {
			m_Player->Move(false, i);
		}
	}

	if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT) || Util::Input::IsKeyPressed(Util::Keycode::D)) {
		m_Player->Move(true);
	}
	else if (Util::Input::IsKeyUp(Util::Keycode::RIGHT) || Util::Input::IsKeyPressed(Util::Keycode::D)) {
		for (int i = 5;i>0;i--) {
			m_Player->Move(true, i);
		}
	}

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
