//
// Created by Jun on 2025/4/25.
//

#ifndef TRAP_HPP
#define TRAP_HPP

#include "Character.hpp"
#include "Image.hpp"

class Trap : public Character {
public:
    Trap(const glm::vec2& pos, bool isReverse = false);
    bool IsTouchTrap(const glm::vec2& trapPos);
    void Destroy();

private:
    std::shared_ptr<Image> m_TrapImage;
};

#endif //TRAP_HPP
