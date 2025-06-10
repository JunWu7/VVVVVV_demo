//
// Created by Jun on 2025/6/6.
//

#include "Object.hpp"
#include "Util/Image.hpp"


Object::Object(const std::string& ImagePath) {
    SetImage(ImagePath);
}

void Object::SetImage(const std::string& ImagePath) {
    m_ImagePath = std::string(GA_RESOURCE_DIR) + "/Image/Background/" + ImagePath + ".png";
    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}
