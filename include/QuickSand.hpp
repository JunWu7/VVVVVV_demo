//
// Created by Jun on 2025/5/23.
//

#ifndef QUICKSAND_HPP
#define QUICKSAND_HPP

#include "AnimatedObject.hpp"

class QuickSand : public AnimatedObject {
public:
    QuickSand(const glm::vec2& pos, const std::vector<std::string>& animationPaths);
    bool IsTouchQuickSand(const glm::vec2& sandPos);
    void Destroy();
private:
    int m_QuickSandIndex = 0;
    bool m_IsTouch = false;
    const float edge = 1.0;
};


#endif //QUICKSAND_HPP
