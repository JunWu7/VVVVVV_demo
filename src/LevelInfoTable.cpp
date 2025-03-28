//
// Created by Jun on 2025/3/25.
//
#include "LevelInfoTable.hpp"

LevelInfoTable::LevelInfoTable() {
    // WelcomeAboard 關卡資料
    levelMap[LevelID::WelcomeAboard] = LevelData{
        "1.Welcome_Aboard_withnote",        // 圖片檔名
        "1.Welcome_Aboard_background",      // 背景圖片檔名
        LevelID::WelcomeAboard,
        LevelID::WelcomeAboard,
        LevelID::WelcomeAboard,
        LevelID::Conundrum,
        false,                              // 沒有陷阱
        false,                              // 有敵人
        {},                                 // 無陷阱位置
        {}  // 敵人位置
    };

    // Conundrum 關卡資料
    levelMap[LevelID::Conundrum] = LevelData{
        "2.Conundrum",
        "2.Conundrum_background",
        LevelID::Conundrum,
        LevelID::Conundrum,
        LevelID::WelcomeAboard,
        LevelID::Solitude,
        true,
        false,
        {},
        {}
    };

    // Solitude 關卡資料
    levelMap[LevelID::Solitude] = LevelData{
        "3.Solitude",
        "3.Solitude_background",
        LevelID::LeapOfFaith,
        LevelID::Conundrum,
        LevelID::Conundrum,
        LevelID::Conundrum,
        true,
        false,
        {},
        {}
    };

    // LeapOfFaith 關卡資料
    levelMap[LevelID::LeapOfFaith] = LevelData{
        "4.Leap_of_Faith",
        "4.Leap_of_Faith_background",
        LevelID::TrafficJam,
        LevelID::Solitude,
        LevelID::Conundrum,
        LevelID::Conundrum,
        true,
        false,
        {},
        {}
    };

    // TrafficJam 關卡資料
    levelMap[LevelID::TrafficJam] = LevelData{
        "5.Traffic_Jam",
        "5.Traffic_Jam_background",
        LevelID::TrafficJam,
        LevelID::LeapOfFaith,
        LevelID::TrafficJam,
        LevelID::TrafficJam,
        true,
        false,
        {},
        {}
    };


    // ✅ 之後可繼續加
    // levelMap[LevelID::Laboratory] = LevelData{ ... };
    // levelMap[LevelID::FinalZone] = LevelData{ ... };
}

const LevelData& LevelInfoTable::GetLevelData(LevelID id) const {
    return levelMap.at(id);
}
