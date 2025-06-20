//
// Created by Jun on 2025/5/2.
//

#include "SavePoint.hpp"

SavePoint::SavePoint(const glm::vec2& pos, bool isReverse)
    : Object(isReverse ? "SavePointReverse" : "SavePoint")
{
    SetPosition(pos);
}

bool SavePoint::IsTouchSavePoint(const glm::vec2& savePointPos)
{
    return std::abs(savePointPos.x - m_Transform.translation.x) * 2 < (40 + 55) &&
           std::abs(savePointPos.y - m_Transform.translation.y) * 2 < (82 + 61);
}

void SavePoint::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}