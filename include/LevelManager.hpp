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
#include "QuickSand.hpp"
#include "MovingPlatform.hpp"
#include "Trinket.hpp"

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

    bool isStepOnQuickSand(const glm::vec2& Position);

    bool IsTouchQuickSandLeft(const glm::vec2& Position);

    bool IsTouchQuickSandRight(const glm::vec2& Position);

    bool isTouchMovingPlatform(const glm::vec2& Position);

    bool isTouchTrinket(const glm::vec2& Position);

    void preloadAllWalkableMasks(const LevelInfoTable& infoTable);

    void setLevelDataByID(LevelID levelId);

    glm::vec2& getSavePointPosition() {return m_SavePointPosition;}

    void setSavePointPosition(const glm::vec2& position) {m_SavePointPosition = position;}

    void setSavePointIsReverse(bool setting) { m_SavePointIsReverse = setting; }

    void setSavePointLevelID(LevelID levelId) { m_SavePointLevelID = levelId; }

    void setPlayerCantKill() { m_playerCantKill = !m_playerCantKill; }

    LevelID getSavePointLevelID() const { return m_SavePointLevelID; }

    LevelID getCurrentLevelID() const { return m_CurrentLevelID; }

    bool getSavePointIsReverse() const { return m_SavePointIsReverse; }

    bool getMovingPlatformIsVertical() const { return m_movingPlatformIsVertical; }

    bool getMovingPlatformIsIncrement() const { return m_movingPlatformIsIncrement; }

    float getMovingPlatformSpeed() const { return m_movingPlatformSpeed; }

    MovingPlatform *getCurrentPlatform() const { return m_CurrentPlatform; }

    int getDeathCounter() const { return m_deathCounter; }

    int getTrinketCount() const { return m_trinketCount; }

    bool getPlayerCantKill() const { return m_playerCantKill; }

    void updateEnemies();

    void updateMovingPlatforms(const glm::vec2& Position);

    void addDeathCounter() { m_deathCounter++; }

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
    bool m_isInGame = true;
    std::vector<std::shared_ptr<QuickSand>> m_QuickSand;
    std::vector<std::shared_ptr<MovingPlatform>> m_MovingPlatforms;
    bool m_movingPlatformIsVertical = false;
    bool m_movingPlatformIsIncrement = true;
    float m_movingPlatformSpeed = 15.0f;
    MovingPlatform* m_CurrentPlatform = nullptr;

    int m_deathCounter;
    std::vector<bool> m_TrinketTakenMap; // 追蹤每個地圖的 Trinket 狀態
    std::vector<std::shared_ptr<Trinket>> m_Trinkets;
    int m_trinketCount;

    bool m_playerCantKill = false; // 玩家是否不能被殺

    int imageWidth = 1280;
    int imageHeight = 915;

    void setLevel(int entryDirection);

    void setSavePoint();

    void setTrap();

    void setEnemy(int entryDirection);

    void setQuickSandPosition();

    void setMovingPlatform();

    void setTrinket();

    void setWalkableMask(LevelID levelId);

    glm::ivec2 WorldToImageCoords(float wx, float wy) const;

    void clearAllTrap();

    void clearAllSavePoint();

    void clearAllEnemies();

    void clearAllQuickSand();

    void clearAllMovingPlatform();

    void clearAllTrinket();
};

#endif //LEVELMANAGER_HPP
