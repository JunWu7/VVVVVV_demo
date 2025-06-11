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

private:
    std::shared_ptr<Image> m_trinketImage;
};

#endif //TRINKET_HPP
