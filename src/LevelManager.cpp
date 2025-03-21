//
// Created by Jun on 2025/3/21.
//

#include "LevelManager.hpp"

#include "BackgroundImage.hpp"

LevelManager::LevelManager() {
    m_Background = std::make_shared<Image>("1.Welcome Aboard_back", -10);
    m_Level = std::make_shared<Image>("1.Welcome Aboard_withnote", -10);
}

bool LevelManager::isOnTheGround() {
    return false;
}

void LevelManager::isTouchRightWall() {
}

void LevelManager::isTouchLeftWall() {
}

void LevelManager::isTouchUpWall() {
}

void LevelManager::isTouchDownWall() {
}

void LevelManager::isTouchSavePoint() {
}

void LevelManager::isTouchEnemy() {
}

void LevelManager::isTouchTrap() {
}

void LevelManager::setBackGround(std::string) {
}

void LevelManager::setLevel(std::string) {
}

void LevelManager::setSavePoint() {
}

void LevelManager::setTrap() {
}