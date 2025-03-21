//
// Created by Jun on 2025/3/14.
//

#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

//create an interface for the level
class LevelManager : public Util::GameObject {
public:
    LevelManager()  : GameObject(
        std::make_unique<Util::Image>(GA_RESOURCE_DIR"/Image/Background/1.Welcome Aboard.png"), -10) {

    }
    bool isOnTheGround();

    void isTouchRightWall();

    void isTouchLeftWall();

    void isTouchUpWall();

    void isTouchDownWall();

    void isTouchSavePoint();

    void isTouchEnemy();

    void isTouchTrap();

    void setBackGround(std::string);

    void setLevel(std::string);

    void setSavePoint();

    void setTrap();

private:
    std::shared_ptr<Util::Image> m_Background;
    std::shared_ptr<Util::Image> m_Level;


};

#endif //LEVELMANAGER_HPP
