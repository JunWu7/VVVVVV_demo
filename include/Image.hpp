#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class Image : public Util::GameObject {

public:
    Image(std::string Path, float index) : GameObject(
        std::make_unique<Util::Image>(GA_RESOURCE_DIR + Path), index) {
    }

    void ChangeImage(std::string Path) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        temp->SetImage(GA_RESOURCE_DIR + Path + ".png");
    }

private:
};

#endif //IMAGE_HPP
