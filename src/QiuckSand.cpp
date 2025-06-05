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

bool QuickSand::IsTouchQuickSand(const glm::vec2& sandPos) {
    if (IfAnimationEnds()) {
        return false;
    }

    // float dx = std::abs(sandPos.x - m_Transform.translation.x);
    // float dy = std::abs(sandPos.y - m_Transform.translation.y);
    // bool xOverlap = dx < (40 + 83);
    // bool yTouch = std::abs(dy - (82 + 21)) < edge;
    //
    // if (GetCurrentFrame() == 0 && xOverlap && yTouch) {
    //     SetPlaying(true);
    // }
    // return xOverlap && yTouch;

    bool isTouching = std::abs(sandPos.x - m_Transform.translation.x) * 2 < (40 + 128) &&
                      std::abs(sandPos.y - m_Transform.translation.y) * 2 < (82 + 32);

    if (GetCurrentFrame() == 0 && isTouching) {
        SetPlaying(true);
    }

    return isTouching;
}

void QuickSand::Destroy() {
    SetVisible(false);
    m_Drawable.reset();
}