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

void Player::isTouchHeightWall() {
    if (abs(m_Transform.translation.y) >= 540) {
        m_Transform.translation.y *= -1;
        if (m_Transform.translation.y > 0) {
            m_Transform.translation.y -= 10;
        } else {
            m_Transform.translation.y += 10;
        }
    }
}

void Player::isTouchWidthWall() {
    if (abs(m_Transform.translation.x) >= 640) {
        m_Transform.translation.x *= -1;
        if (m_Transform.translation.x > 0) {
            m_Transform.translation.x -= 10;
        } else {
            m_Transform.translation.x += 10;
        }
    }
}
