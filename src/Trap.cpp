//
// Created by Jun on 2025/4/25.
//

#include "Trap.hpp"

Trap::Trap(const glm::vec2& pos, bool isReverse)
    : Object(isReverse ? "SpikeReverse" : "Spike")
{
    SetPosition(pos);
}

bool Trap::IsTouchTrap(const glm::vec2& trapPos) {
    return std::abs(trapPos.x - m_Transform.translation.x) * 2 < (40 + 49) &&
           std::abs(trapPos.y - m_Transform.translation.y) * 2 < (82 + 52);
}

void Trap::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}
