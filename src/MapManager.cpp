//
// Created by Jun on 2025/5/16.
//

#include "MapManager.hpp"
#include "ImageLoader.hpp"

MapManager::MapManager() {
    map_Background = std::make_shared<Image>("Map/allMap", 9);
    map_Background->SetVisible(true);
    map_Background->m_Transform.translation.x = 0;
    map_Background->m_Transform.translation.y = MAP_HIDE_Y;
    map_Mask.resize(MAP_SIZE);
    map_IsMaskCover.resize(MAP_SIZE, true);
    map_IsMaskCover[0] = false;
    map_currentMap.resize(MAP_SIZE);
    map_WhichIsCurrentMap.resize(MAP_SIZE, false);
    map_WhichIsCurrentMap[0] = true;
    map_currentMapTitle.resize(MAP_SIZE);
    map_WhichIsCurrentMapTitle.resize(MAP_SIZE, false);
    map_WhichIsCurrentMapTitle[0] = true;

    for (int i = 0; i < MAP_SIZE; i++) {
        map_Mask[i] = std::make_shared<Image>("Map/unvisitedMap/" + std::to_string(i+1), 10);
        map_Mask[i]->SetVisible(true);
        map_Mask[i]->m_Transform.translation.x = 0;
        map_Mask[i]->m_Transform.translation.y = MAP_HIDE_Y;
        map_currentMap[i] = std::make_shared<Image>("Map/currentMap/" + std::to_string(i+1), 15);
        map_currentMap[i]->SetVisible(false);
        map_currentMap[i]->m_Transform.translation.x = 0;
        map_currentMap[i]->m_Transform.translation.y = MAP_HIDE_Y;
        map_currentMapTitle[i] = std::make_shared<Image>("Map/MapTitles/(" + std::to_string(i+1) + ")", 20);
        map_currentMapTitle[i]->SetVisible(false);
        map_currentMapTitle[i]->m_Transform.translation.x = 0;
        map_currentMapTitle[i]->m_Transform.translation.y = MAP_HIDE_Y;
    }
    map_currentMap[0]->SetVisible(true);
    map_currentMapTitle[0]->SetVisible(true);

    // 初始化文字物件
    statsTimerText = std::make_shared<MapText>();
    statsTimerText->m_Transform.translation = {0, MAP_HIDE_Y};
    statsTimerText->SetVisible(true);
    statsTimerText->SetZIndex(10);

    statsDeathCounterText = std::make_shared<MapText>();
    statsDeathCounterText->m_Transform.translation = {0, MAP_HIDE_Y};
    statsDeathCounterText->SetVisible(true);
    statsDeathCounterText->SetZIndex(10);

    statsTrinketsCounterText = std::make_shared<MapText>();
    statsTrinketsCounterText->m_Transform.translation = {-220, MAP_HIDE_Y};
    statsTrinketsCounterText->SetVisible(true);
    statsTrinketsCounterText->SetZIndex(10);

    // 初始化頁面為地圖頁面
    map_StatsBackground = std::make_shared<Image>("Map/mapStats", 9);
    map_StatsBackground->SetVisible(true);
    map_StatsBackground->m_Transform.translation.x = 0;
    map_StatsBackground->m_Transform.translation.y = MAP_HIDE_Y;
    map_CrewBackground = std::make_shared<Image>("Map/mapCrew", 9);
    map_CrewBackground->SetVisible(true);
    map_CrewBackground->m_Transform.translation.x = 0;
    map_CrewBackground->m_Transform.translation.y = MAP_HIDE_Y;
    map_SaveBackground = std::make_shared<Image>("Map/mapSave", 9);
    map_SaveBackground->SetVisible(true);
    map_SaveBackground->m_Transform.translation.x = 0;
    map_SaveBackground->m_Transform.translation.y = MAP_HIDE_Y;
}

void MapManager::callMap() {
    map_Background->m_Transform.translation.y += MAP_MOVE_SPEED;
    map_CrewBackground->m_Transform.translation.y += MAP_MOVE_SPEED;
    map_SaveBackground->m_Transform.translation.y += MAP_MOVE_SPEED;
    map_StatsBackground->m_Transform.translation.y += MAP_MOVE_SPEED;
    statsTrinketsCounterText->m_Transform.translation.y += MAP_MOVE_SPEED;
    statsTimerText->m_Transform.translation.y += MAP_MOVE_SPEED;
    statsDeathCounterText->m_Transform.translation.y += MAP_MOVE_SPEED;
    for (int j = 0; j < MAP_SIZE; j++) {
        map_Mask[j]->m_Transform.translation.y += MAP_MOVE_SPEED;
        map_currentMap[j]->m_Transform.translation.y += MAP_MOVE_SPEED;
        map_currentMapTitle[j]->m_Transform.translation.y += MAP_MOVE_SPEED;
    }
    if (map_Background->m_Transform.translation.y + MAP_MOVE_SPEED >= 0) {
        map_Background->m_Transform.translation.y = MAP_SHOW_Y;
        map_CrewBackground->m_Transform.translation.y = MAP_SHOW_Y;
        map_SaveBackground->m_Transform.translation.y = MAP_SHOW_Y;
        map_StatsBackground->m_Transform.translation.y = MAP_SHOW_Y;
        statsTrinketsCounterText->m_Transform.translation.y = 205;
        statsTimerText->m_Transform.translation.y = -190; // Adjusted for visibility
        statsDeathCounterText->m_Transform.translation.y = MAP_SHOW_Y;
        for (int j = 0; j < MAP_SIZE; j++) {
            map_Mask[j]->m_Transform.translation.y = MAP_SHOW_Y;
            map_currentMap[j]->m_Transform.translation.y = MAP_SHOW_Y;
            map_currentMapTitle[j]->m_Transform.translation.y = MAP_SHOW_Y;
        }
        mapMoveComplete = true;
    }
}

void MapManager::returnMap() {
    map_Background->m_Transform.translation.y -= MAP_MOVE_SPEED;
    for (int j = 0; j < MAP_SIZE; j++) {
        map_Mask[j]->m_Transform.translation.y -= MAP_MOVE_SPEED;
        map_currentMap[j]->m_Transform.translation.y -= MAP_MOVE_SPEED;
        map_currentMapTitle[j]->m_Transform.translation.y -= MAP_MOVE_SPEED;
    }
    if (map_Background->m_Transform.translation.y - MAP_MOVE_SPEED <= MAP_HIDE_Y) {
        map_Background->m_Transform.translation.y = MAP_HIDE_Y;
        for (int j = 0; j < MAP_SIZE; j++) {
            map_Mask[j]->m_Transform.translation.y = MAP_HIDE_Y;
            map_currentMap[j]->m_Transform.translation.y = MAP_HIDE_Y;
            map_currentMapTitle[j]->m_Transform.translation.y = MAP_HIDE_Y;
        }
        mapMoveComplete = true;
    }
}

void MapManager::updateMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        if (map_IsMaskCover[i] == true) {
            map_Mask[i]->SetVisible(true);
        }
        else {
            map_Mask[i]->SetVisible(false);
        }
        if (map_WhichIsCurrentMap[i] == true) {
            map_currentMap[i]->SetVisible(true);
            map_currentMapTitle[i]->SetVisible(true);
        }
        else {
            map_currentMap[i]->SetVisible(false);
            map_currentMapTitle[i]->SetVisible(false);
        }
    }
}

void MapManager::mapCurrent(int index) {
    for (int i = 0; i < MAP_SIZE; i++) {
        if (i == index) {
            map_WhichIsCurrentMap[i] = true;
            map_WhichIsCurrentMapTitle[i] = true;
        }
        else {
            map_WhichIsCurrentMap[i] = false;
            map_WhichIsCurrentMapTitle[i] = false;
        }
    }
}

void MapManager::NextPage() {
    switch (currentPage) {
        case MAP:
            updatePage(CREW);
            break;
        case CREW:
            updatePage(STATS);
            break;
        case STATS:
            updatePage(SAVE);
            break;
        case SAVE:
            updatePage(MAP);
            break;
    }
}

void MapManager::PreviousPage() {
    switch (currentPage) {
        case MAP:
            updatePage(SAVE);
            break;
        case CREW:
            updatePage(MAP);
            break;
        case STATS:
            updatePage(CREW);
            break;
        case SAVE:
            updatePage(STATS);
            break;
    }
}

void MapManager::updatePage(Page page) {
    // // 隱藏所有頁面
    setAllMapInvisible();

    switch (page) {
        case MAP:
            updateMap();
            map_Background->SetVisible(true);
            break;
        case CREW:
            map_CrewBackground->SetVisible(true);
            break;
        case STATS:
            map_StatsBackground->SetVisible(true);
            statsTimerText->SetVisible(true);
            statsTrinketsCounterText->SetVisible(true);
            statsDeathCounterText->SetVisible(true);
            break;
        case SAVE:
            map_SaveBackground->SetVisible(true);
            break;
    }
    currentPage = page;
}

void MapManager::updateStats(int deathCount) {
    // 更新文字
    // std::ostringstream timerStream;
    // timerStream << "Time: " << std::fixed << std::setprecision(1) << timer;

    statsDeathCounterText->SetText(std::to_string(deathCount));
}

std::string MapManager::formatTime(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    std::ostringstream timeStream;
    timeStream << std::setw(2) << std::setfill('0') << minutes << ":"
               << std::setw(2) << std::setfill('0') << seconds;

    return timeStream.str();
}

void MapManager::addTime() {
    if (++frameCounter % 60 == 0) { // 每 60 frame 更新一次
        frameCounter = 0;
        statsTimerText->SetText(formatTime(++timer));
    }
}

void MapManager::setAllMapInvisible() {
    // 隱藏所有地圖相關物件
    map_Background->SetVisible(false);
    for (auto& mask : map_Mask) mask->SetVisible(false);
    for (auto& currentMap : map_currentMap) currentMap->SetVisible(false);
    // for (auto& currentMapTitle : map_currentMapTitle) currentMapTitle->SetVisible(false);
    statsTimerText->SetVisible(false);
    statsDeathCounterText->SetVisible(false);
    statsTrinketsCounterText->SetVisible(false);
    map_StatsBackground->SetVisible(false);
    map_CrewBackground->SetVisible(false);
    map_SaveBackground->SetVisible(false);
}