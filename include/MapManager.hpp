//
// Created by Jun on 2025/5/16.
//

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

#include "Util/GameObject.hpp"
#include "Image.hpp"
#include "LevelInfoTable.hpp"
#include "MapText.hpp"
#include <iomanip>

class MapManager : public Util::GameObject {
public:
    enum Page { MAP, CREW, STATS, SAVE };

    MapManager();

    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> TakeChildren() const {
        std::vector<std::shared_ptr<Util::GameObject>> result;

        // 將 map_Background 加入結果中（需轉型）
        result.push_back(std::static_pointer_cast<Util::GameObject>(map_Background));

        // 將 foundedMask 的每個 shared_ptr 加入結果中（需轉型）
        for (const auto& mask : map_Mask) {
            result.push_back(std::static_pointer_cast<Util::GameObject>(mask));
        }

        // 將 map_currentMap 的每個 shared_ptr 加入結果中（需轉型）
        for (const auto& currentMap : map_currentMap) {
            result.push_back(std::static_pointer_cast<Util::GameObject>(currentMap));
        }

        // 將 map_currentMapTitle 的每個 shared_ptr 加入結果中（需轉型）
        for (const auto& currentMapTitle : map_currentMapTitle) {
            result.push_back(std::static_pointer_cast<Util::GameObject>(currentMapTitle));
        }

        // 將 stats crew 和 save 背景加入結果中
        result.push_back(std::static_pointer_cast<Util::GameObject>(map_StatsBackground));
        result.push_back(std::static_pointer_cast<Util::GameObject>(map_CrewBackground));
        result.push_back(std::static_pointer_cast<Util::GameObject>(map_SaveBackground));

        // 將文字物件加入結果中
        result.push_back(std::static_pointer_cast<Util::GameObject>(statsTimerText));
        result.push_back(std::static_pointer_cast<Util::GameObject>(statsDeathCounterText));
        result.push_back(std::static_pointer_cast<Util::GameObject>(statsTrinketsCounterText));


        return result;
    }

    bool isMapMoveComplete() const { return mapMoveComplete; }

    void setMapMoveComplete( bool complete ) { mapMoveComplete = complete; }

    void callMap();

    void returnMap();

    void setMapCalled( bool called ) { mapCalled = called; }

    bool isMapCalled() const { return mapCalled; }

    void updateMap();

    void mapVisited(int index) { map_IsMaskCover[index] = false; }

    void mapCurrent(int index);

    void NextPage();

    void PreviousPage();

    void updatePage(Page page = MAP);

    void updateStats(int deathCount);

    void addTime();

private:
    std::shared_ptr<Image> map_Background;
    std::shared_ptr<Image> map_StatsBackground;
    std::shared_ptr<Image> map_CrewBackground;
    std::shared_ptr<Image> map_SaveBackground;
    std::vector<std::shared_ptr<Image>> map_Mask;
    std::vector<bool> map_IsMaskCover;
    std::vector<std::shared_ptr<Image>> map_currentMap;
    std::vector<bool> map_WhichIsCurrentMap;
    std::vector<std::shared_ptr<Image>> map_currentMapTitle;
    std::vector<bool> map_WhichIsCurrentMapTitle;
    bool mapCalled = false;
    bool mapMoveComplete = true;
    const float MAP_MOVE_SPEED = 50;
    const int MAP_SIZE = 25;
    const float MAP_HIDE_Y = -950;
    const float MAP_SHOW_Y = 0;
    std::string formatTime(int totalSeconds);
    void setAllMapInvisible();

    Page currentPage = MAP;
    std::shared_ptr<MapText> statsTimerText;
    std::shared_ptr<MapText> statsDeathCounterText;
    std::shared_ptr<MapText> statsTrinketsCounterText;
    int frameCounter = 0;
    int timer = 0;
    int deathCounter = 0;
    int trinketsCounter = 0;
};


#endif //MAPMANAGER_HPP
