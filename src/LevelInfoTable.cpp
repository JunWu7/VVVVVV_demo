//
// Created by Jun on 2025/3/25.
//
#include "LevelInfoTable.hpp"

LevelInfoTable::LevelInfoTable() {
    // 🛰️ SpaceStation 關卡資料
    levelMap[LevelID::SpaceStation] = LevelData{
        "space_main.png",                   // 圖片檔名
        "space_bg.png",                     // 背景圖片檔名
        false,                              // 沒有陷阱
        true,                               // 有敵人
        {},                                 // 無陷阱位置
        { glm::vec2(100, 120), glm::vec2(200, 150) }  // 敵人位置
    };

    // ✅ 之後可繼續加
    // levelMap[LevelID::Laboratory] = LevelData{ ... };
    // levelMap[LevelID::FinalZone] = LevelData{ ... };
}

const LevelData& LevelInfoTable::Get(LevelID id) const {
    return levelMap.at(id);
}
