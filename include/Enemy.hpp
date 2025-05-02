//
// Created by Jun on 2025/5/2.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Character.hpp"
#include "Image.hpp"

class Enemy : public Character {
public:
    Enemy(const std::string& imagePath, const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& size, bool isIncrement, float speed = 15.0f);
    bool IsTouchEnemy(const glm::vec2& enemyPos);
    void Update();
    void Destroy();

private:
    std::shared_ptr<Image> m_EnemyImage;
    glm::vec2 m_Point1;
    glm::vec2 m_Point2;
    float m_Speed;          // 每次更新的移動速度
    bool m_IsIncrement;       // 目前方向
    glm::vec2 m_ImageSize;
};

#endif //ENEMY_HPP
