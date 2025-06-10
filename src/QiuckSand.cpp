//
// Created by Jun on 2025/6/6.
//

#include "QuickSand.hpp"

QuickSand::QuickSand(const glm::vec2& pos, const std::vector<std::string>& animationPaths)
    : AnimatedObject(animationPaths) {
    // m_Drawable = std::make_shared<Util::Animation>(animationPaths, false, 500, false, 0);
    SetPosition(pos);
    SetCurrentFrame(0);
    SetInterval(100);
    SetPlaying(false);
}

bool QuickSand::isStepOnQuickSand(const glm::vec2& sandPos) {
    if (IfAnimationEnds()) {
        SetVisible(false);
        return false;
    }

    float dx = std::abs(sandPos.x - m_Transform.translation.x);
    float dy = std::abs(sandPos.y - m_Transform.translation.y);

    bool isTouching = dx * 2 < (40 + 128) && dy * 2 < (82 + 36);

    // 「上下方向剛好接觸」的容忍範圍判斷
    float expectedY = (82 + 32) / 2.0f;  // 一半的高度總和
    bool isStepOn = dx * 2 < (40 + 128) && std::abs(dy - expectedY) < 16.0f;

    if (GetCurrentFrame() == 0 && isStepOn) {
        SetPlaying(true);
    }

    return isStepOn;
}

bool QuickSand::IsTouchQuickSandLeft(const glm::vec2& sandPos) {
    float playerRightEdge = sandPos.x + 20.0f;
    float quickSandLeftEdge = m_Transform.translation.x - 64.0f;

    // 水平接觸判斷（角色右邊超過 QuickSand 左邊一點點）
    bool xOverlap = playerRightEdge >= quickSandLeftEdge && playerRightEdge <= quickSandLeftEdge + 4.0f;

    // 垂直是否重疊（角色中線與 QuickSand 高度相交）
    float playerTop = sandPos.y - 41.0f;
    float playerBottom = sandPos.y + 41.0f;
    float quickSandTop = m_Transform.translation.y - 16.0f;
    float quickSandBottom = m_Transform.translation.y + 16.0f;
    bool yOverlap = !(playerBottom < quickSandTop || playerTop > quickSandBottom);

    return xOverlap && yOverlap;
}

bool QuickSand::IsTouchQuickSandRight(const glm::vec2& sandPos) {
    float playerLeftEdge = sandPos.x - 20.0f;
    float quickSandRightEdge = m_Transform.translation.x + 64.0f;

    // 水平接觸判斷（角色左邊超過 QuickSand 右邊一點點）
    bool xOverlap = playerLeftEdge <= quickSandRightEdge && playerLeftEdge >= quickSandRightEdge - 4.0f;

    // 垂直是否重疊
    float playerTop = sandPos.y - 41.0f;
    float playerBottom = sandPos.y + 41.0f;
    float quickSandTop = m_Transform.translation.y - 16.0f;
    float quickSandBottom = m_Transform.translation.y + 16.0f;
    bool yOverlap = !(playerBottom < quickSandTop || playerTop > quickSandBottom);

    return xOverlap && yOverlap;
}

bool QuickSand::isInBox(float x, float y) {
    return (x >= m_Transform.translation.x - 64 && x <= m_Transform.translation.x + 64 &&
            y >= m_Transform.translation.y - 16 && y <= m_Transform.translation.y + 16);
}

void QuickSand::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}