//
// Created by Jun on 2025/6/12.
//

#include "Trinket.hpp"

Trinket::Trinket(const glm::vec2& pos)
    : Object("trinket")
{
    SetPosition(pos);
}

bool Trinket::IsTouchTrinket(const glm::vec2& trinketPos) {
    return std::abs(trinketPos.x - m_Transform.translation.x) * 2 < (40 + 68) &&
           std::abs(trinketPos.y - m_Transform.translation.y) * 2 < (82 + 67);
}

void Trinket::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}