//
// Created by Jun on 2025/6/6.
//

#include "MovingPlatform.hpp"

MovingPlatform::MovingPlatform(const std::string& imagePath, const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& startP, const glm::vec2& size, float speed, bool isVertical, bool isIncrement)
    : Object(imagePath),
      m_Point1(p1),
      m_Point2(p2),
      m_ImageSize(size),
      m_Speed(speed),
      m_IsVertical(isVertical),
      m_IsIncrement(isIncrement)
{
    SetPosition(startP);
    // m_IsIncrement = true;
}

bool MovingPlatform::IsTouchMovingPlatform(const glm::vec2& Pos)
{
    // return std::abs(Pos.x - m_Transform.translation.x) * 2 < (40 + m_ImageSize.x) &&
    //        std::abs(Pos.y - m_Transform.translation.y) * 2 < (82 + m_ImageSize.y);
    float dx = std::abs(Pos.x - m_Transform.translation.x);
    float dy = std::abs(Pos.y - m_Transform.translation.y);

    bool isTouching = dx * 2 < (40 + 128) && dy * 2 < (82 + 36);

    // 「上下方向剛好接觸」的容忍範圍判斷
    float expectedY = (82 + m_ImageSize.y) / 2.0f;  // 一半的高度總和
    bool isStepOn = dx * 2 < (40 + m_ImageSize.x) && std::abs(dy - expectedY) < (m_ImageSize.y/2);

    return isStepOn;
}

void MovingPlatform::Update() {
    glm::vec2 pos = GetPosition();

    glm::vec2 target = m_IsIncrement ? m_Point2 : m_Point1;

    // 朝向 target 移動
    glm::vec2 direction = glm::normalize(target - pos);
    pos += direction * m_Speed;

    // 若抵達或超過目標點 → 反向
    if ((m_IsIncrement && glm::distance(pos, m_Point2) < m_Speed) ||
        (!m_IsIncrement && glm::distance(pos, m_Point1) < m_Speed)) {
        m_IsIncrement = !m_IsIncrement;
        }

    SetPosition(pos);
}

void MovingPlatform::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}
