//
// Created by Jun on 2025/3/6.
//

#include "Player.hpp"

void Player::Update() {
    if (isGravityFlipped) {
        m_Transform.translation.y -= 10;
    } else {
        m_Transform.translation.y += 10;
    }
}

void Player::Move(bool isRight) {
    if (isRight) {
        m_Transform.translation.x += 10;
    } else {
        m_Transform.translation.x -= 10;
    }
}
