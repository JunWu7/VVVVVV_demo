//
// Created by Jun on 2025/4/25.
//

#include "Trap.hpp"

Trap::Trap(const glm::vec2& pos, bool isReverse)
    : Character(
        std::string(GA_RESOURCE_DIR) +
        (isReverse ? "/Image/Background/SpikeReverse.png"
                   : "/Image/Background/Spike.png")
      )
{
    SetPosition(pos);
}

bool Trap::IsTouchTrap(const glm::vec2& playerPos)
{
    return std::abs(playerPos.x - m_Transform.translation.x) * 2 < (40 + 49) &&
           std::abs(playerPos.y - m_Transform.translation.y) * 2 < (82 + 52);
}

void Trap::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}
