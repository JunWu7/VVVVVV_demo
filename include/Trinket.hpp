//
// Created by Jun on 2025/6/12.
//

#ifndef TRINKET_HPP
#define TRINKET_HPP

#include "Object.hpp"
#include "Image.hpp"

class Trinket : public Object {
public:
    Trinket(const glm::vec2& pos);
    bool IsTouchTrinket(const glm::vec2& trinketPos);
    void Destroy();
    bool IsTaken() const { return taken; }
    void Take() { taken = true; }

private:
    std::shared_ptr<Image> m_trinketImage;
    bool taken = false; // 是否已經被拿取
};

#endif //TRINKET_HPP
