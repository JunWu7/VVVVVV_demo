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
#include "SavePoint.hpp"
#include "Enemy.hpp"

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

    bool isTouchSavePoint(const glm::vec2& Position);

    bool isTouchEnemy(const glm::vec2& Position);

    bool isTouchTrap(const glm::vec2& Position);

    void preloadAllWalkableMasks(const LevelInfoTable& infoTable);

    void setLevelDataByID(LevelID levelId);

    glm::vec2& getSavePointPosition() {return m_SavePointPosition;}

    void setSavePointPosition(const glm::vec2& position) {m_SavePointPosition = position;}

    bool getSavePointIsReverse() const { return m_SavePointIsReverse; }

    void setSavePointIsReverse(bool setting) { m_SavePointIsReverse = setting; }

    void setSavePointLevelID(LevelID levelId) { m_SavePointLevelID = levelId; }

    LevelID getSavePointLevelID() const { return m_SavePointLevelID; }

    LevelID getCurrentLevelID() const { return m_CurrentLevelID; }

    void updateEnemies();

    bool isSteppedOnQuickSand() const { return m_isSteppedOnQuickSand; }

    void setIsinGame(bool setting) { m_isInGame = setting; }

    bool isInGame() const { return m_isInGame; }

private:
    std::shared_ptr<Image> m_Level;
    std::shared_ptr<Image> m_Background;
    std::unordered_map<LevelID, std::vector<bool>> walkableMaskMap;
    std::vector<bool> walkableMask;
    std::shared_ptr<LevelInfoTable> m_LevelInfoTable;
    LevelData levelData;
    std::vector<std::shared_ptr<Trap>> m_Traps;
    std::vector<std::shared_ptr<SavePoint>> m_SavePoints;
    glm::vec2 m_SavePointPosition = {0, 0};
    LevelID m_SavePointLevelID;
    bool  m_SavePointIsReverse = false;
    LevelID m_CurrentLevelID;
    std::vector<std::shared_ptr<Enemy>> m_Enemies;
    bool m_isSteppedOnQuickSand = false;
    bool m_isInGame = true;

    int imageWidth = 1280;
    int imageHeight = 915;

    void setLevel(int entryDirection);

    void setSavePoint();

    void setTrap();

    void setEnemy(int entryDirection);

    void setWalkableMask(LevelID levelId);

    glm::ivec2 WorldToImageCoords(float wx, float wy) const;

    void clearAllTrap();

    void clearAllSavePoint();

    void clearAllEnemies();

};

#endif //LEVELMANAGER_HPP
