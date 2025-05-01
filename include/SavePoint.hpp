//
// Created by Jun on 2025/5/2.
//

#ifndef SAVEPOINT_HPP
#define SAVEPOINT_HPP

#include "Character.hpp"
#include "Image.hpp"

class SavePoint : public Character {
public:
    SavePoint(const glm::vec2& pos, bool isReverse = false);
    bool IsTouchSavePoint(const glm::vec2& playerPos);
    void Destroy();

private:
    std::shared_ptr<Image> m_SavepointImage;
};

#endif //SAVEPOINT_HPP
