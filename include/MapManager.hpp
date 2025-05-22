//
// Created by Jun on 2025/5/16.
//

#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

#include "Util/GameObject.hpp"
#include "Image.hpp"
#include "LevelInfoTable.hpp"
#include <unordered_map>
#include  "Trap.hpp"
#include "SavePoint.hpp"
#include "Enemy.hpp"

class MapManager : public Util::GameObject {
public:
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

private:
    std::shared_ptr<Image> map_Background;
    std::vector<std::shared_ptr<Image>> map_Mask;
    std::vector<bool> map_IsMaskCover;
    std::vector<std::shared_ptr<Image>> map_currentMap;
    std::vector<bool> map_WhichIsCurrentMap;
    bool mapCalled = false;
    bool mapMoveComplete = true;

    int imageWidth = 1280;
    int imageHeight = 915;

};


#endif //MAPMANAGER_HPP
