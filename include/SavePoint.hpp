//
// Created by Jun on 2025/5/2.
//

#ifndef SAVEPOINT_HPP
#define SAVEPOINT_HPP

#include "Object.hpp"
#include "Image.hpp"

class SavePoint : public Object {
public:
    SavePoint(const glm::vec2& pos, bool isReverse = false);
    bool IsTouchSavePoint(const glm::vec2& savePointPos);
    void Destroy();

private:
    std::shared_ptr<Image> m_SavepointImage;
};

#endif //SAVEPOINT_HPP
