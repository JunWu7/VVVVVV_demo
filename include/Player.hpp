//
// Created by Jun on 2025/3/5.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AnimatedCharacter.hpp"

// Inheritance AnimatedCharacter
class Player : public AnimatedCharacter {
private:
    bool isGravityFlipped = false;

public:
    // Constructor
    explicit Player(const std::vector<std::string>& AnimationPaths) : AnimatedCharacter(AnimationPaths) {}

    // Destructor
    ~Player() = default;

    // Method
    void FlipGravity() { isGravityFlipped = !isGravityFlipped; }
    void Update();
    void Move(bool isRight);
    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }
    
};
#endif //PLAYER_HPP
