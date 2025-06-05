//
// Created by Jun on 2025/6/6.
//

#include "AnimatedObject.hpp"

AnimatedObject::AnimatedObject(const std::vector<std::string>& AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}

bool AnimatedObject::IfAnimationEnds() const {
    auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
}
