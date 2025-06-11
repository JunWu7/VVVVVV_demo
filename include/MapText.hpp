#ifndef TASKTEXT_HPP
#define TASKTEXT_HPP

#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"

class MapText : public Util::GameObject {
public:
    MapText() : GameObject(
            std::make_unique<Util::Text>(GA_RESOURCE_DIR"/Font/PressStart2P-Regular.ttf", 30,
                                         "0",
                                         Util::Color::FromName(Util::Colors::GRAY)),
            100) {
        // m_Transform.translation = {0.0F, -270.F};
    }

    void SetText(const std::string& text) {
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetText(text);
    }

private:
    // inline static std::string append_string_views(std::string_view sv1, std::string_view sv2) {
    //     return std::string(sv1) + "\n" + std::string(sv2);
    // }
    //
    // static constexpr std::string_view s_PhaseTasks[6] = {
    //         "Replace the image of m_giraffe with giraffe.png in Resources!",
    //         "Make the giraffe move into the red area using the keyboard!",
    //         "Make the chest disappear when the giraffe touches it!",
    //         "Write a program to give your bee friend an animation!",
    //         "Write a program to open the door when your character touches it!",
    //         "Design a program to countdown, stop animation after OK display"
    // };
    // static constexpr std::string_view s_Validation = "Press Enter to validate";
};


#endif //TASKTEXT_HPP
