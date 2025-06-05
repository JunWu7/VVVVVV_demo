//
// Created by Jun on 2025/6/6.
//

#ifndef ANIMATED_OBJECT_HPP
#define ANIMATED_OBJECT_HPP

#include <vector>
#include <string>

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"

class AnimatedObject : public Util::GameObject {

public:
    explicit AnimatedObject(const std::vector<std::string>& AnimationPaths);

    [[nodiscard]] bool IsLooping() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetLooping();
    }

    [[nodiscard]] bool IsPlaying() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetState() == Util::Animation::State::PLAY;
    }

    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->SetLooping(looping);
    }

    void SetPlaying(bool play) {
        if (play) {
            std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->Play();
        }
        else {
            std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->Pause();
        }
    }

    void SetCurrentFrame(int frame) {
        std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->SetCurrentFrame(frame);
    }

    size_t GetCurrentFrame() {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetCurrentFrameIndex();
    }

    void Draw() {
        std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->Play();
        std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->Pause();
    }

    [[nodiscard]] bool IfAnimationEnds() const;

    void SetPosition(const glm::vec2& Position) {
        m_Transform.translation = Position;
    }

    void SetInterval(int interval) {
        std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->SetInterval(interval);
    }

};

#endif //ANIMATED_OBJECT_HPP