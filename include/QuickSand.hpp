//
// Created by Jun on 2025/5/23.
//

#ifndef QUICKSAND_HPP
#define QUICKSAND_HPP

#include "AnimatedObject.hpp"

class QuickSand : public AnimatedObject {
public:
    QuickSand(const glm::vec2& pos, const std::vector<std::string>& animationPaths);
    bool isStepOnQuickSand(const glm::vec2& sandPos);
    bool IsTouchQuickSandLeft(const glm::vec2& sandPos);
    bool IsTouchQuickSandRight(const glm::vec2& sandPos);
    void Destroy();
private:
    int m_QuickSandIndex = 0;
    bool m_IsTouch = false;
    bool isInBox(float x, float y);
};


#endif //QUICKSAND_HPP
