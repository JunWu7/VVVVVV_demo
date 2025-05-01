//
// Created by Jun on 2025/5/2.
//

#include "SavePoint.hpp"

SavePoint::SavePoint(const glm::vec2& pos, bool isReverse)
    : Character(
        std::string(GA_RESOURCE_DIR) +
        (isReverse ? "/Image/Background/SavePointReverse.png"
                   : "/Image/Background/SavePoint.png")
      )
{
    SetPosition(pos);
}

bool SavePoint::IsTouchSavePoint(const glm::vec2& playerPos)
{
    return std::abs(playerPos.x - m_Transform.translation.x) * 2 < (40 + 55) &&
           std::abs(playerPos.y - m_Transform.translation.y) * 2 < (82 + 61);
}

void SavePoint::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}