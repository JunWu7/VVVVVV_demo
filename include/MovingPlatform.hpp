//
// Created by Jun on 2025/6/6.
//

#ifndef MOVINGPLATFORM_HPP
#define MOVINGPLATFORM_HPP

#include "Object.hpp"
#include "Image.hpp"

class MovingPlatform : public Object {
public:
    MovingPlatform(const std::string& imagePath, const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& startP, const glm::vec2& size, float speed = 15.0f, bool isVertical = false, bool isIncrement = true);

    [[nodiscard]] const glm::vec2& GetPoint1() const { return m_Point1; }
    [[nodiscard]] const glm::vec2& GetPoint2() const { return m_Point2; }
    [[nodiscard]] const glm::vec2& GetImageSize() const { return m_ImageSize; }
    bool IsTouchMovingPlatform(const glm::vec2& Pos);
    void Update();
    void Destroy();
    bool GetVertical () const { return m_IsVertical; }
    float GetSpeed () const { return m_Speed; }
    bool GetIsIncrement () const { return m_IsIncrement; }

private:
    std::shared_ptr<Image> m_MovingPlatform;
    glm::vec2 m_Point1;
    glm::vec2 m_Point2;
    float m_Speed;          // 每次更新的移動速度
    glm::vec2 m_ImageSize;
    bool m_IsIncrement; // 目前方向，true 為向 Point2 移動，false 為向 Point1 移動
    bool m_IsVertical; // 是否為垂直移動平台
};

#endif //MOVINGPLATFORM_HPP
