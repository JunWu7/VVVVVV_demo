//
// Created by Jun on 2025/3/25.
//

#ifndef LEVELINFOTABLE_HPP
#define LEVELINFOTABLE_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <glm/vec2.hpp>

// --- Enum 定義 ---
enum class LevelID {
    WelcomeAboard,
    Conundrum,
    Solitude,
    LeapOfFaith,
    TrafficJam,
    AtmosphericFilteringUnit,
    ItsASecretToNobody,
    LinearCollider,
    SecuritySweep,
    GentryAndDolly,
    CommsRelay,
    TheYesMen,
    StopAndReflect,
    TrenchWarfare,
    VStitch,
    BBBBusted,
    TheSensibleRoom,
    BooThinkFast,
    Driller,
    ExhaustChute,
    Sorrow,
    Quicksand,
    TheTombOfMadCarew,
    BrassSentUsUnderTheTop,
    AWrinkleInTime
    // 可依照實作添加更多關卡
};

// --- 每個關卡的資料結構 ---
struct LevelData {
    std::string imageName;                // 主場景圖片
    std::string backgroundName;           // 背景圖片
    LevelID upWall;
    LevelID downWall;
    LevelID leftWall;
    LevelID rightWall;
    bool hasTraps;                        // 是否有陷阱
    bool hasEnemies;                      // 是否有敵人
    std::vector<glm::vec2> trapPositions; // 陷阱位置陣列
    std::vector<glm::vec2> enemyPositions;// 敵人位置陣列
};

// --- LevelInfoTable 類別 ---
class LevelInfoTable {
public:
    LevelInfoTable();                              // 建構子：初始化所有關卡資料
    const LevelData& GetLevelData(LevelID id) const;        // 查詢特定關卡資料

private:
    std::unordered_map<LevelID, LevelData> levelMap; // 關卡資料表
};

#endif //LEVELINFOTABLE_HPP
