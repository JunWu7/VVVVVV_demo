//
// Created by Jun on 2025/5/2.
//

#include "Enemy.hpp"

Enemy::Enemy(const std::string& imagePath, const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& size, bool isIncrement, float speed)
    : Character(imagePath),
      m_Point1(p1),
      m_Point2(p2),
      m_ImageSize(size),
      m_IsIncrement(isIncrement),
      m_Speed(speed)
{
    SetPosition(m_IsIncrement ? m_Point1 : m_Point2);
}

bool Enemy::IsTouchEnemy(const glm::vec2& enemyPos)
{
    return std::abs(enemyPos.x - m_Transform.translation.x) * 2 < (40 + m_ImageSize.x) &&
           std::abs(enemyPos.y - m_Transform.translation.y) * 2 < (82 + m_ImageSize.y);
}

void Enemy::Update() {
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

void Enemy::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}