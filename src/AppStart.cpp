#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    std::vector<std::string> playerImages;
    playerImages.reserve(1);
    playerImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/playerNew.png");
    playerImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/playerNewReverse.png");
    m_Player = std::make_shared<Player>(playerImages);
    m_Player->SetPosition({0, 0});
    m_Player->SetZIndex(5);
    m_Player->SetVisible(true);
    m_Root.AddChild(m_Player);

    m_LM = std::make_shared<LevelManager>();
    m_Root.AddChildren(m_LM->TakeChildren());

    m_Map = std::make_shared<MapManager>();
    m_Root.AddChildren(m_Map->TakeChildren());

    m_CurrentState = State::UPDATE;
}
