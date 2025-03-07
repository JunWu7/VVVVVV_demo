#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    std::vector<std::string> playerImages;
    playerImages.reserve(1);
    playerImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/Player.png");
    m_Player = std::make_shared<Player>(playerImages);
    m_Player->SetPosition({0, 0});
    m_Player->SetZIndex(50);
    m_Player->SetVisible(true);
    m_Root.AddChild(m_Player);

    /*m_Giraffe = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/giraffe.png");
    m_Giraffe->SetPosition({-112.5f, -140.5f});
    m_Giraffe->SetZIndex(50);
    m_Root.AddChild(m_Giraffe);


    m_Chest = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/chest.png");
    m_Chest->SetZIndex(5);
    m_Chest->SetPosition({197.5f, -3.5f});
    m_Chest->SetVisible(false);
    m_Root.AddChild(m_Chest);

    std::vector<std::string> beeImages;
    beeImages.reserve(2);
    for (int i = 0; i < 2; ++i) {
        beeImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/bee_" + std::to_string(i + 1) + ".png");
    }

    m_Bee = std::make_shared<AnimatedCharacter>(beeImages);
    m_Bee->SetZIndex(5);
    m_Bee->SetVisible(false);
    m_Root.AddChild(m_Bee);

    for (int i = 0; i < 3; ++i) {
        m_Doors.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/door_close.png"));
        m_Doors[i]->SetZIndex(5);
        m_Doors[i]->SetPosition({205.5f - 80.f * i, -3.5f});
        m_Doors[i]->SetVisible(false);
        m_Root.AddChild(m_Doors[i]);
    }

    // TODO: The counting down ball for phase 6

    std::vector<std::string> ballImages;
    ballImages.reserve(4);
    for (int i = 0; i < 3; ++i) {
        ballImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/ball-" + std::to_string(i + 1) + ".png");
    }
    ballImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/ball-OK.png");

    m_Ball = std::make_shared<AnimatedCharacter>(ballImages);
    m_Ball->SetZIndex(5);
    m_Ball->SetPosition({ -112.5f, -140.5f });
    m_Ball->SetVisible(false);
    m_Root.AddChild(m_Ball);

    //

    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildren());
    */

    m_CurrentState = State::UPDATE;
}
