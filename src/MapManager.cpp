//
// Created by Jun on 2025/5/16.
//

#include "MapManager.hpp"
#include "ImageLoader.hpp"

MapManager::MapManager() {
    map_Background = std::make_shared<Image>("Map/allMap", 9);
    map_Background->SetVisible(true);
    map_Background->m_Transform.translation.x = 0;
    map_Background->m_Transform.translation.y = -950;
    map_Mask.resize(25);
    map_IsMaskCover.resize(25, true);
    map_IsMaskCover[0] = false;
    map_currentMap.resize(25);
    map_WhichIsCurrentMap.resize(25, false);
    map_WhichIsCurrentMap[0] = true;
    map_currentMapTitle.resize(25);
    map_WhichIsCurrentMapTitle.resize(25, false);
    map_WhichIsCurrentMapTitle[0] = true;

    for (int i = 0; i < 25; i++) {
        map_Mask[i] = std::make_shared<Image>("Map/unvisitedMap/" + std::to_string(i+1), 10);
        map_Mask[i]->SetVisible(true);
        map_Mask[i]->m_Transform.translation.x = 0;
        map_Mask[i]->m_Transform.translation.y = -950;
        map_currentMap[i] = std::make_shared<Image>("Map/currentMap/" + std::to_string(i+1), 15);
        map_currentMap[i]->SetVisible(false);
        map_currentMap[i]->m_Transform.translation.x = 0;
        map_currentMap[i]->m_Transform.translation.y = -950;
        map_currentMapTitle[i] = std::make_shared<Image>("Map/MapTitles/(" + std::to_string(i+1) + ")", 20);
        map_currentMapTitle[i]->SetVisible(false);
        map_currentMapTitle[i]->m_Transform.translation.x = 0;
        map_currentMapTitle[i]->m_Transform.translation.y = -950;
    }
    map_currentMap[0]->SetVisible(true);
    map_currentMapTitle[0]->SetVisible(true);
}

void MapManager::callMap() {
    map_Background->m_Transform.translation.y += 19;
    for (int j = 0; j < 25; j++) {
        map_Mask[j]->m_Transform.translation.y += 19;
        map_currentMap[j]->m_Transform.translation.y += 19;
        map_currentMapTitle[j]->m_Transform.translation.y += 19;
    }
    if (map_Background->m_Transform.translation.y == 0) {
        mapMoveComplete = true;
    }
}

void MapManager::returnMap() {
    map_Background->m_Transform.translation.y -= 19;
    for (int j = 0; j < 25; j++) {
        map_Mask[j]->m_Transform.translation.y -= 19;
        map_currentMap[j]->m_Transform.translation.y -= 19;
        map_currentMapTitle[j]->m_Transform.translation.y -= 19;
    }
    if (map_Background->m_Transform.translation.y == -950) {
        mapMoveComplete = true;
    }
}

void MapManager::updateMap() {
    for (int i = 0; i < 25; i++) {
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
    for (int i = 0; i < 25; i++) {
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