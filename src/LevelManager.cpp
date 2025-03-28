//
// Created by Jun on 2025/3/21.
//

#include "LevelManager.hpp"

#include "BackgroundImage.hpp"

//public method

LevelManager::LevelManager() {
    m_LevelInfoTable = std::make_shared<LevelInfoTable>();
    levelData = m_LevelInfoTable->GetLevelData(LevelID::WelcomeAboard);
    m_Level = std::make_shared<Image>(levelData.imageName, -10);
    m_Background = std::make_shared<Image>(levelData.backgroundName, -10);
    walkableMask.resize(1280 * 950);
}

bool LevelManager::isOnTheGround(const glm::vec2& position) {
    return false;
}

void LevelManager::isTouchUpWall() {
    levelData = m_LevelInfoTable->GetLevelData(levelData.upWall);
    setLevel();
}

void LevelManager::isTouchDownWall() {
    levelData = m_LevelInfoTable->GetLevelData(levelData.downWall);
    setLevel();
}

void LevelManager::isTouchRightWall() {
    levelData = m_LevelInfoTable->GetLevelData(levelData.rightWall);
    setLevel();
}

void LevelManager::isTouchLeftWall() {
    levelData = m_LevelInfoTable->GetLevelData(levelData.leftWall);
    setLevel();
}

void LevelManager::isTouchSavePoint() {
}

void LevelManager::isTouchEnemy() {
}

void LevelManager::isTouchTrap() {
}

//private method

void LevelManager::setLevel() {
    m_Level->ChangeImage(levelData.imageName);
    m_Background->ChangeImage(levelData.backgroundName);
}

void LevelManager::setSavePoint() {
}

void LevelManager::setTrap() {
}