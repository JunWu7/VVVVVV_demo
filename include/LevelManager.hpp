//
// Created by Jun on 2025/3/14.
//

#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include "Util/GameObject.hpp"
#include "Image.hpp"
#include "LevelInfoTable.hpp"
#include <unordered_map>
#include  "Trap.hpp"

class LevelManager : public Util::GameObject {
public:
    LevelManager();

    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> TakeChildren() const {
        return {m_Level, m_Background};
    }

    bool isMoveAble(const glm::vec2& position, bool isIncrement, bool isVertical);

    void isTouchRightWall();

    void isTouchLeftWall();

    void isTouchUpWall();

    void isTouchDownWall();

    void isTouchSavePoint();

    void isTouchEnemy();

    bool isTouchTrap(const glm::vec2& Position);

    void preloadAllWalkableMasks(const LevelInfoTable& infoTable);

    void setLevelDataByID(LevelID levelId);

private:
    std::shared_ptr<Image> m_Level;
    std::shared_ptr<Image> m_Background;
    std::unordered_map<LevelID, std::vector<bool>> walkableMaskMap;
    std::vector<bool> walkableMask;
    std::shared_ptr<LevelInfoTable> m_LevelInfoTable;
    LevelData levelData;
    std::vector<std::shared_ptr<Trap>> m_Traps;

    int imageWidth = 1280;
    int imageHeight = 915;

    void setLevel();

    void setSavePoint();

    void setTrap();

    void setWalkableMask(LevelID levelId);

    glm::ivec2 WorldToImageCoords(float wx, float wy) const;

    void clearAllTrap();
};

#endif //LEVELMANAGER_HPP
