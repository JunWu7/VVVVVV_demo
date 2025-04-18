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
    walkableMask.resize(imageWidth * imageHeight);
    preloadAllWalkableMasks(*m_LevelInfoTable);
    levelData = m_LevelInfoTable->GetLevelData(LevelID::WelcomeAboard);
    m_Level = std::make_shared<Image>(levelData.imageName, -10);
    m_Background = std::make_shared<Image>(levelData.backgroundName, -10);
    setWalkableMask(LevelID::WelcomeAboard);
}

bool LevelManager::isMoveAble(const glm::vec2& position, bool isIncrement, bool isVertical) {
    glm::ivec2 imageCoord = WorldToImageCoords(position.x, position.y);
    if (isVertical) {
        if (isIncrement) {
            imageCoord.y += 61;
        } else {
            imageCoord.y -= 61;
        }
        if ((imageCoord.y >= 915 || imageCoord.y <= 0)) {
            return true;
        }
        return (walkableMask[imageCoord.y * imageWidth + imageCoord.x] && walkableMask[imageCoord.y * imageWidth + (imageCoord.x + 15)] && walkableMask[imageCoord.y * imageWidth + (imageCoord.x - 15)]);
    } else {
        if (isIncrement) {
            imageCoord.x += 30;
        } else {
            imageCoord.x -= 30;
        }
        // if ((imageCoord.x <= 30 || imageCoord.x >= 1250)) {
        //     return true;
        // }
        return (walkableMask[imageCoord.y * imageWidth + imageCoord.x] && walkableMask[(imageCoord.y + 31) * imageWidth + imageCoord.x] && walkableMask[(imageCoord.y - 31) * imageWidth + imageCoord.x]);
    }
}

void LevelManager::isTouchUpWall() {
    setWalkableMask(levelData.upWall);
    levelData = m_LevelInfoTable->GetLevelData(levelData.upWall);
    setLevel();
}

void LevelManager::isTouchDownWall() {
    setWalkableMask(levelData.downWall);
    levelData = m_LevelInfoTable->GetLevelData(levelData.downWall);
    setLevel();
}

void LevelManager::isTouchRightWall() {
    setWalkableMask(levelData.rightWall);
    levelData = m_LevelInfoTable->GetLevelData(levelData.rightWall);
    setLevel();
}

void LevelManager::isTouchLeftWall() {
    setWalkableMask(levelData.leftWall);
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
