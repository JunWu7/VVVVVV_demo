//
// Created by Jun on 2025/3/21.
//

#include "LevelManager.hpp"
#include "ImageLoader.hpp"

// #define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//public method

LevelManager::LevelManager() {
    m_LevelInfoTable = std::make_shared<LevelInfoTable>();
    walkableMask.resize(imageWidth * imageHeight);
    preloadAllWalkableMasks(*m_LevelInfoTable);
    levelData = m_LevelInfoTable->GetLevelData(LevelID::WelcomeAboard);
    m_Level = std::make_shared<Image>(levelData.imageName, -10);
    m_Background = std::make_shared<Image>(levelData.backgroundName, -10);
    setWalkableMask(LevelID::WelcomeAboard);
    m_SavePointLevelID = LevelID::WelcomeAboard;
    m_CurrentLevelID = LevelID::WelcomeAboard;
    m_deathCounter = 0;
    m_TrinketTakenMap = {false, false};
    m_trinketCount = 0;
}

bool LevelManager::isMoveAble(const glm::vec2& position, bool isIncrement, bool isVertical) {
    glm::ivec2 imageCoord = WorldToImageCoords(position.x, position.y);
    if (isVertical) {
        if (isIncrement) {
            imageCoord.y += 47;
        } else {
            imageCoord.y -= 47;
        }
        if ((imageCoord.y >= 915 || imageCoord.y <= 0)) {
            return true;
        }
        return (walkableMask[imageCoord.y * imageWidth + imageCoord.x] && walkableMask[imageCoord.y * imageWidth + (imageCoord.x + 15)] && walkableMask[imageCoord.y * imageWidth + (imageCoord.x - 15)]);
    }
    else {
        if (isIncrement) {
            imageCoord.x += 25;
        } else {
            imageCoord.x -= 25;
        }
    }
    bool maskAns = (walkableMask[imageCoord.y * imageWidth + imageCoord.x] && walkableMask[(imageCoord.y + 18) * imageWidth + imageCoord.x] && walkableMask[(imageCoord.y - 18) * imageWidth + imageCoord.x]);
    return maskAns;
}

void LevelManager::isTouchUpWall() {
    setWalkableMask(levelData.upWall);
    m_CurrentLevelID = levelData.upWall;
    levelData = m_LevelInfoTable->GetLevelData(levelData.upWall);
    setLevel(1);
}

void LevelManager::isTouchDownWall() {
    setWalkableMask(levelData.downWall);
    m_CurrentLevelID = levelData.downWall;
    levelData = m_LevelInfoTable->GetLevelData(levelData.downWall);
    setLevel(2);
}

void LevelManager::isTouchRightWall() {
    setWalkableMask(levelData.rightWall);
    m_CurrentLevelID = levelData.rightWall;
    levelData = m_LevelInfoTable->GetLevelData(levelData.rightWall);
    setLevel(3);
}

void LevelManager::isTouchLeftWall() {
    setWalkableMask(levelData.leftWall);
    m_CurrentLevelID = levelData.leftWall;
    levelData = m_LevelInfoTable->GetLevelData(levelData.leftWall);
    setLevel(4);
}

bool LevelManager::isTouchSavePoint(const glm::vec2& Position) {
    for (const auto& savePoint : m_SavePoints) {
        if (savePoint->IsTouchSavePoint(Position)) {
            m_SavePointLevelID = m_CurrentLevelID;
            if (savePoint->GetImagePath() == std::string(GA_RESOURCE_DIR) + "/Image/Background/SavePointReverse.png") {
                m_SavePointIsReverse = true;
            } else {
                m_SavePointIsReverse = false;
            }
            return true;
        }
    }
    return false;
}

bool LevelManager::isTouchEnemy(const glm::vec2& Position) {
    for (const auto& enemy : m_Enemies) {
        if (enemy->IsTouchEnemy(Position)) {
            return true;
        }
    }
    return false;
}

bool LevelManager::isTouchTrap(const glm::vec2& Position) {
    for (const auto& trap : m_Traps) {
        if (trap->IsTouchTrap(Position)) {
            return true;
        }
    }
    return false;
}

bool LevelManager::isStepOnQuickSand(const glm::vec2& Position) {
    for (const auto& quickSand : m_QuickSand) {
        if (quickSand->isStepOnQuickSand(Position)) {
            return true;
        }
    }
    return false;
}

bool LevelManager::IsTouchQuickSandLeft(const glm::vec2& Position) {
    for (const auto& quickSand : m_QuickSand) {
        if (quickSand->IsTouchQuickSandLeft(Position)) {
            return true;
        }
    }
    return false;
}

bool LevelManager::IsTouchQuickSandRight(const glm::vec2& Position) {
    for (const auto& quickSand : m_QuickSand) {
        if (quickSand->IsTouchQuickSandRight(Position)) {
            return true;
        }
    }
    return false;
}

bool LevelManager::isTouchMovingPlatform(const glm::vec2& Position) {
    for (const auto& MovingPlatform : m_MovingPlatforms) {
        if (MovingPlatform->IsTouchMovingPlatform(Position)) {
            m_movingPlatformIsVertical = MovingPlatform->GetVertical();
            m_movingPlatformIsIncrement = MovingPlatform->GetIsIncrement();
            m_movingPlatformSpeed = MovingPlatform->GetSpeed();
            return true;
        }
    }
    return false;
}

bool LevelManager::isTouchTrinket(const glm::vec2& Position) {
    for (const auto& trinket : m_Trinkets) {
        if (trinket->IsTouchTrinket(Position) && !trinket->IsTaken()) {
            if (getCurrentLevelID() == LevelID::ItsASecretToNobody) {
                m_TrinketTakenMap[0] = true;
            } else if (getCurrentLevelID() == LevelID::TrenchWarfare) {
                m_TrinketTakenMap[1] = true;
            }
            m_trinketCount++;
            trinket->Take();
            trinket->SetVisible(false);
            return true;
        }
    }
    return false;
}

//private method

void LevelManager::setLevel(int entryDirection) {
    clearAllTrap();
    clearAllSavePoint();
    clearAllEnemies();
    clearAllQuickSand();
    clearAllMovingPlatform();
    clearAllTrinket();
    m_Level->ChangeImage(levelData.imageName);
    m_Background->ChangeImage(levelData.backgroundName);
    if (levelData.hasTraps) {setTrap();}
    if (levelData.hasSavePoint) {setSavePoint();}
    if (levelData.hasEnemies) {setEnemy(entryDirection);}
    if (levelData.hasQuickSand) {setQuickSandPosition();}
    if (levelData.hasMovingPlatform) {setMovingPlatform();}
    if (levelData.hasTrinket) {setTrinket();}
}

void LevelManager::setEnemy(int entryDirection) {
    for (const auto& enemyInfos : levelData.enemyInfos) {
        m_Enemies.push_back(std::make_shared<Enemy>(enemyInfos.imagePath, enemyInfos.position1, enemyInfos.position2,
            enemyInfos.size, enemyInfos.isIncrement, enemyInfos.speed, enemyInfos.isEnemyReverseAble, entryDirection));
    }
    for (const auto& enemy : m_Enemies) {
        enemy->SetZIndex(0);
        enemy->SetVisible(true);
        m_Level->AddChild(enemy);
    }
}

void LevelManager::setSavePoint() {
    for (const auto& pos : levelData.savePointPositions) {
        m_SavePoints.push_back(std::make_shared<SavePoint>(pos));
    }
    for (const auto& pos : levelData.saveReversePositions) {
        m_SavePoints.push_back(std::make_shared<SavePoint>(pos, true));
    }
    for (const auto& savePoint : m_SavePoints) {
        savePoint->SetZIndex(0);
        savePoint->SetVisible(true);
        m_Level->AddChild(savePoint);
    }
}

void LevelManager::setTrap() {
    for (const auto& pos : levelData.trapPositions) {
        m_Traps.push_back(std::make_shared<Trap>(pos));
    }
    for (const auto& pos : levelData.trapReversePositions) {
        m_Traps.push_back(std::make_shared<Trap>(pos, true));
    }
    for (const auto& trap : m_Traps) {
        trap->SetZIndex(0);
        trap->SetVisible(true);
        m_Level->AddChild(trap);
    }
}

void LevelManager::setQuickSandPosition() {
    for (const auto& quickSanfInfos : levelData.quickSandPositions) {
        std::vector<std::string> temp;
        for (int i = 0; i < 5; ++i) {
            temp.push_back(std::string(GA_RESOURCE_DIR) + "/Image/Background/" + quickSanfInfos.color + "Sand" + std::to_string(i) + ".png");
        }
        m_QuickSand.push_back(std::make_shared<QuickSand>(quickSanfInfos.position, temp));
    }
    for (const auto& quickSand : m_QuickSand) {
        quickSand->SetZIndex(0);
        quickSand->SetVisible(true);
        m_Level->AddChild(quickSand);
    }
}

void LevelManager::setMovingPlatform() {
    for (const auto& movingPlatformInfos : levelData.movingPlatformPositions) {
        m_MovingPlatforms.push_back(std::make_shared<MovingPlatform>(movingPlatformInfos.imagePath, movingPlatformInfos.position1, movingPlatformInfos.position2,
            movingPlatformInfos.startP, movingPlatformInfos.size, movingPlatformInfos.speed, movingPlatformInfos.isVertical, movingPlatformInfos.isIncrement));
    }
    for (const auto& movingPlatform : m_MovingPlatforms) {
        movingPlatform->SetZIndex(0);
        movingPlatform->SetVisible(true);
        m_Level->AddChild(movingPlatform);
    }
}

void LevelManager::setTrinket() {
    if ((getCurrentLevelID() == LevelID::ItsASecretToNobody && !m_TrinketTakenMap[0]) ||
        (getCurrentLevelID() == LevelID::TrenchWarfare && !m_TrinketTakenMap[1])) {
        for (const auto& pos : levelData.trinketPositions) {
            m_Trinkets.push_back(std::make_shared<Trinket>(pos));
        }
        for (const auto& trinket : m_Trinkets) {
            trinket->SetZIndex(0);
            trinket->SetVisible(true);
            m_Level->AddChild(trinket);
        }
    }
}

void LevelManager::setWalkableMask(LevelID levelId) {
    walkableMask = walkableMaskMap[levelId];
}

void LevelManager::preloadAllWalkableMasks(const LevelInfoTable& infoTable) {
    // 根據 enum 的所有值初始化（你可以預先建立一個 list）
    std::vector<LevelID> allLevels = {
        LevelID::WelcomeAboard, LevelID::Conundrum, LevelID::Solitude,
        LevelID::LeapOfFaith, LevelID::TrafficJam, LevelID::AtmosphericFilteringUnit,
        LevelID::ItsASecretToNobody, LevelID::LinearCollider, LevelID::SecuritySweep,
        LevelID::GentryAndDolly, LevelID::CommsRelay, LevelID::TheYesMen,
        LevelID::StopAndReflect, LevelID::TrenchWarfare, LevelID::VStitch,
        LevelID::BBBBusted, LevelID::TheSensibleRoom, LevelID::BooThinkFast,
        LevelID::Driller, LevelID::ExhaustChute, LevelID::Sorrow,
        LevelID::Quicksand, LevelID::TheTombOfMadCarew,
        LevelID::BrassSentUsUnderTheTop, LevelID::AWrinkleInTime
    };

    for (LevelID levelId : allLevels) {
        const LevelData& data = infoTable.GetLevelData(levelId);
        ImageLoader img(std::string(GA_RESOURCE_DIR) + "/Image/Background/" + data.imageName + ".png");

        std::vector<bool> mask(img.width * img.height);
        for (int y = 0; y < img.height; ++y) {
            for (int x = 0; x < img.width; ++x) {
                mask[y * img.width + x] = !img.IsPixelOpaque(x, y);  // alpha==0 => 可走
            }
        }

        walkableMaskMap[levelId] = std::move(mask);
    }
}

glm::ivec2 LevelManager::WorldToImageCoords(float wx, float wy) const {
    int imageX = static_cast<int>(wx + 1280 / 2);
    int imageY = static_cast<int>(950 / 2 - wy); // 反轉 y
    return { imageX, imageY };
}

void LevelManager::setLevelDataByID(LevelID levelId) {
    setWalkableMask(levelId);
    m_CurrentLevelID = levelId;
    levelData = m_LevelInfoTable->GetLevelData(levelId);
    setLevel(0);
}

void LevelManager::clearAllTrap() {
    for (const auto& trap : m_Traps) {
        trap->Destroy();
    }
    m_Traps.clear();
}

void LevelManager::clearAllSavePoint() {
    for (const auto& savePoint : m_SavePoints) {
        savePoint->Destroy();
    }
    m_SavePoints.clear();
}

void LevelManager::clearAllEnemies() {
    for (const auto& enemy : m_Enemies) {
        enemy->Destroy();
    }
    m_Enemies.clear();
}

void LevelManager::clearAllQuickSand() {
    for (const auto& quickSand : m_QuickSand) {
        quickSand->Destroy();
    }
    m_QuickSand.clear();
}

void LevelManager::clearAllMovingPlatform() {
    for (const auto& movingPlatform : m_MovingPlatforms) {
        movingPlatform->Destroy();
    }
    m_MovingPlatforms.clear();
}

void LevelManager::clearAllTrinket() {
    for (const auto& trinket : m_Trinkets) {
        trinket->Destroy();
    }
    m_Trinkets.clear();
}


void LevelManager::updateEnemies() {
    if (levelData.hasEnemies) {
        for (const auto& enemy : m_Enemies) {
            enemy->Update();
        }
    }
}

void LevelManager::updateMovingPlatforms(const glm::vec2& Position) {
    if (levelData.hasMovingPlatform) {
        m_CurrentPlatform = nullptr;
        for (const auto& movingPlatform : m_MovingPlatforms) {
            movingPlatform->Update();
            if (movingPlatform->IsTouchMovingPlatform(Position)) {
                m_CurrentPlatform = movingPlatform.get();
            }
        }
    }
}