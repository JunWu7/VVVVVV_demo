#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Renderer.hpp"
#include "Character.hpp"
#include "Util/Text.hpp"
#include "PhaseResourceManger.hpp"
#include "AnimatedCharacter.hpp"
#include "Player.hpp"
#include "LevelManager.hpp"
#include "MapManager.hpp"

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:

    void ValidTask();

private:
    State m_CurrentState = State::START;

    Util::Renderer m_Root;

    std::shared_ptr<Player> m_Player;

    std::shared_ptr<LevelManager> m_LM;

    bool fallAble = false;

    std::shared_ptr<MapManager> m_Map;
};

#endif
