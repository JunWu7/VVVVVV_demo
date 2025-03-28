//
// Created by Jun on 2025/3/14.
//

#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include "Util/GameObject.hpp"
#include "Image.hpp"
#include "LevelInfoTable.hpp"

class LevelManager : public Util::GameObject {
public:
    LevelManager();

    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> TakeChildren() const {
        return {m_Level, m_Background};
    }

    bool isOnTheGround(const glm::vec2& position);

    void isTouchRightWall();

    void isTouchLeftWall();

    void isTouchUpWall();

    void isTouchDownWall();

    void isTouchSavePoint();

    void isTouchEnemy();

    void isTouchTrap();

private:
    std::shared_ptr<Image> m_Level;
    std::shared_ptr<Image> m_Background;
    std::vector<bool> walkableMask;
    std::shared_ptr<LevelInfoTable> m_LevelInfoTable;
    LevelData levelData;

    void setLevel();

    void setSavePoint();

    void setTrap();
};

#endif //LEVELMANAGER_HPP
