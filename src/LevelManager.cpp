//
// Created by Jun on 2025/3/21.
//

#include "LevelManager.hpp"
#include "BackgroundImage.hpp"
#include "ImageLoader.hpp"

// #define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//public method

LevelManager::LevelManager() {
    m_LevelInfoTable = std::make_shared<LevelInfoTable>();
    levelData = m_LevelInfoTable->GetLevelData(LevelID::WelcomeAboard);
    m_Level = std::make_shared<Image>(levelData.imageName, -10);
    m_Background = std::make_shared<Image>(levelData.backgroundName, -10);
    walkableMask.resize(imageWidth * imageHeight);
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
    // setWalkableMask();
}

void LevelManager::setSavePoint() {
}

void LevelManager::setTrap() {
}

void LevelManager::setWalkableMask() {
    ImageLoader image(levelData.imageName);

    imageWidth = image.width;
    imageHeight = image.height;

    walkableMask.resize(imageWidth * imageHeight);

    for (int y = 0; y < imageHeight; ++y) {
        for (int x = 0; x < imageWidth; ++x) {
            walkableMask[y * imageWidth + x] = !image.IsPixelOpaque(x, y);  // 透明 = 可走
        }
    }

    // stbi_image_free(data); // 釋放圖片記憶體
}

// glm::ivec2 WorldToImageCoords(float wx, float wy) const {
//     int imageX = static_cast<int>(wx + imageWidth / 2);
//     int imageY = static_cast<int>(imageHeight / 2 - wy); // 反轉 y
//     return { imageX, imageY };
// }
