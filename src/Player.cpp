//
// Created by Jun on 2025/3/6.
//

#include "Player.hpp"

void Player::Update() {
    if (isGravityFlipped) {
        m_Transform.translation.y -= 15;
    } else {
        m_Transform.translation.y += 15;
    }
}

void Player::Move(bool isRight, int speed) {
    if (isRight) {
        m_Transform.translation.x += speed;
    } else {
        m_Transform.translation.x -= speed;
    }
}
