//
// Created by Jun on 2025/3/6.
//

#include "Player.hpp"

void Player::FlipGravity() {
    isGravityFlipped = !isGravityFlipped;
    if (isGravityFlipped) {
        SetCurrentFrame(1);
        Draw();
    }
    else {
        SetCurrentFrame(0);
        Draw();
    }
}


void Player::Update() {
    if (isGravityFlipped) {
        m_Transform.translation.y += 15;
    } else {
        m_Transform.translation.y -= 15;
    }
}

void Player::Move(bool isRight, int speed) {
    if (isRight) {
        m_Transform.translation.x += speed;
    } else {
        m_Transform.translation.x -= speed;
    }
}

void Player::MoveY(bool isUp, int speed) {
    if (isUp) {
        m_Transform.translation.y += speed;
    } else {
        m_Transform.translation.y -= speed;
    }
}

bool Player::isTouchUpWall() {
    if (m_Transform.translation.y >= 452) {
        m_Transform.translation.y = -377.5;
        return true;
    }
    return false;
}

bool Player::isTouchDownWall() {
    if (m_Transform.translation.y <= -387.5) {
        m_Transform.translation.y = 465;
        return true;
    }
    return false;
}

bool Player::isTouchLeftWall() {
    if (m_Transform.translation.x <= -610) {
        m_Transform.translation.x *= -1;
        m_Transform.translation.x -= 10;
        return true;
    }
    return false;
}

bool Player::isTouchRightWall() {
    if (m_Transform.translation.x >= 610) {
        m_Transform.translation.x *= -1;
        m_Transform.translation.x += 10;
        return true;
    }
    return false;
}
