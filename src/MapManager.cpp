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
}

void MapManager::callMap() {
    map_Background->m_Transform.translation.y += MAP_MOVE_SPEED;
    for (int j = 0; j < MAP_SIZE; j++) {
        map_Mask[j]->m_Transform.translation.y += MAP_MOVE_SPEED;
        map_currentMap[j]->m_Transform.translation.y += MAP_MOVE_SPEED;
        map_currentMapTitle[j]->m_Transform.translation.y += MAP_MOVE_SPEED;
    }
    if (map_Background->m_Transform.translation.y + MAP_MOVE_SPEED >= 0) {
        map_Background->m_Transform.translation.y = MAP_SHOW_Y;
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