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
    bool isFlipAble = true;

public:
    // Constructor
    explicit Player(const std::vector<std::string>& AnimationPaths) : AnimatedCharacter(AnimationPaths) {}

    // Destructor
    ~Player() = default;

    // Method
    void FlipGravity();

    bool GetGravityFlipped() { return isGravityFlipped; }

    void SetFlipAble(bool flipAble) { isFlipAble = flipAble; }

    void Update();

    void Move(bool isRight, int speed = 15);

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    bool GetFlipAble() { return isFlipAble; };

    bool isTouchRightWall();

    bool isTouchLeftWall();

    bool isTouchUpWall();

    bool isTouchDownWall();

    // void flipCharacterIm

};
#endif //PLAYER_HPP
