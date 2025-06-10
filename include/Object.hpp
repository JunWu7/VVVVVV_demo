//
// Created by Jun on 2025/6/6.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

#include "Util/GameObject.hpp"

class Object : public Util::GameObject {
public:
    explicit Object(const std::string& ImagePath);

    Object(const Object&) = delete;

    Object(Object&&) = delete;

    Object& operator=(const Object&) = delete;

    Object& operator=(Object&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    void ChangePositionUp() { m_Transform.translation.y += 20; }

    void ChangePositionDown() { m_Transform.translation.y -= 20; }

    void ChangePositionLeft() { m_Transform.translation.x -= 20; }

    void ChangePositionRight() { m_Transform.translation.x += 20; }

    [[nodiscard]] bool IfCollides(const std::shared_ptr<Object>& other) const {
        if(m_Transform.translation.x >= other->GetPosition().x && m_Transform.translation.y >= other->GetPosition().y)
        {
            return true;
        }
        return false;
    }

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};

#endif //OBJECT_HPP
