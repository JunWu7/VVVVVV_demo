//
// Created by Jun on 2025/3/25.
//
#include "LevelInfoTable.hpp"

LevelInfoTable::LevelInfoTable() {
    // WelcomeAboard 關卡資料
    levelMap[LevelID::WelcomeAboard] = LevelData{
        "1.WelcomeAboardWithNote",        // 圖片檔名
        "1.WelcomeAboardBackground",      // 背景圖片檔名
        LevelID::WelcomeAboard,
        LevelID::WelcomeAboard,
        LevelID::WelcomeAboard,
        LevelID::Conundrum,
        false,                              // 沒有陷阱
        false,
        false,// 有敵人
        {},                                 // 無陷阱位置
        {},
        {},
        {},
        {}  // 敵人位置
    };

    // Conundrum 關卡資料
    levelMap[LevelID::Conundrum] = LevelData{
        "2.Conundrum",
        "2.ConundrumBackground",
        LevelID::Conundrum,
        LevelID::Conundrum,
        LevelID::WelcomeAboard,
        LevelID::Solitude,
        true,
        false,
        false,
        {{-201, -303}, {-151, -303}, {-101, -303}, {-51, -303},{-1, -303},
            {49, -303}, {99, -303}, {149, -303}, {199, -303}},
        {},
        {},
        {},
        {}
    };

    // Solitude 關卡資料
    levelMap[LevelID::Solitude] = LevelData{
        "3.Solitude",
        "3.SolitudeBackground",
        LevelID::LeapOfFaith,
        LevelID::Solitude,
        LevelID::Conundrum,
        LevelID::Solitude,
        false,
        false,
        true,
        {},
        {},
        {},
        {{-30, -227}},
        {}
    };

    // LeapOfFaith 關卡資料
    levelMap[LevelID::LeapOfFaith] = LevelData{
        "4.LeapOfFaith",
        "4.LeapOfFaithBackground",
        LevelID::TrafficJam,
        LevelID::Solitude,
        LevelID::LeapOfFaith,
        LevelID::LeapOfFaith,
        false,
        false,
        false,
        {},
        {},
        {},
        {},
        {}
    };

    // TrafficJam 關卡資料
    levelMap[LevelID::TrafficJam] = LevelData{
        "5.TrafficJam",
        "5.TrafficJamBackground",
        LevelID::TrafficJam,
        LevelID::LeapOfFaith,
        LevelID::AtmosphericFilteringUnit,
        LevelID::TrafficJam,
        false,
        true,
        true,
        {},
        {},
        {
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/5.enemy.png",   {220, -80}, {220, 210}, {90, 130}, true, 10.0f},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/5.enemy.png",   {-100, 85}, {-100, 375}, {90, 130}, false, 10.0f},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/5.enemy.png",   {-415, -80}, {-415, 210}, {90, 130}, true, 10.0f}},
        {},
        {{317.5, -287.5}}
    };

    // AtmosphericFilteringUnit
    levelMap[LevelID::AtmosphericFilteringUnit] = LevelData{
        "6.AtmosphericFilteringUnit",
        "6.AtmosphericFilteringUnitBackground",
        LevelID::AtmosphericFilteringUnit,
        LevelID::ItsASecretToNobody,
        LevelID::LinearCollider,
        LevelID::TrafficJam,
        true,
        false,
        true,
        {{-70, -303}, {-25, -303}, {20, -303}, {65, -303}, {110, -303},{155, -303}},
        {{-300, 360},{-253.125, 360},{-206.25, 360},{-159.375,360},{-112.5, 360},
            {-65.625, 360},{-18.75, 360},{28.125, 360},{75, 360}},
        {},
        {{-165, -195}},
        {{160, 255}}
    };

    // ItsASecretToNobody
    levelMap[LevelID::ItsASecretToNobody] = LevelData{
        "7.ItsASecretToNobody",
        "7.ItsASecretToNobodyBackground",
        LevelID::AtmosphericFilteringUnit,
        LevelID::ItsASecretToNobody,
        LevelID::ItsASecretToNobody,
        LevelID::ItsASecretToNobody,
        true,
        false,
        true,
        {{-430, -175},{-390, -175},{-350, -175},{-140, -175},
            {-100, -175},{-60, -175},{-20, -175},{20, -175},{60, -175}},
        {{-300, 136},{-255, 136},{-210, 136},{-165, 136},{-120, 136},{80, 136}, {125, 136}, {170, 136}},
        {},
        {{255, -130}},
        {}
    };
    // {-460, -175}

    // LinearCollider
    levelMap[LevelID::LinearCollider] = LevelData{
        "8.LinearCollider",
        "8.LinearColliderBackground",
        LevelID::LinearCollider,
        LevelID::LinearCollider,
        LevelID::SecuritySweep,
        LevelID::AtmosphericFilteringUnit,
        false,
        true,
        true,
        {},
        {},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/8.enemy.png",   {-290, 100}, {290, 100}, {128, 66}, true, 6.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/8.enemy.png",   {-290, -62}, {290, -62}, {128, 66}, false, 6.0f}},
        {{-513, -225}},
        {{510, 255}}
    };

    // SecuritySweep
    levelMap[LevelID::SecuritySweep] = LevelData{
        "9.SecuritySweep",
        "9.SecuritySweepBackground",
        LevelID::SecuritySweep,
        LevelID::GentryAndDolly,
        LevelID::SecuritySweep,
        LevelID::LinearCollider,
        false,
        true,
        true,
        {},
        {},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/9.point.png",   {186, 345}, {186, -214}, {67, 67}, false, 15.0f}},
        {{62, 25}},
        {}
    };

    // GentryAndDolly
    levelMap[LevelID::GentryAndDolly] = LevelData{
        "10.GentryAndDolly",
        "10.GentryAndDollyBackground",
        LevelID::SecuritySweep,
        LevelID::TheYesMen,
        LevelID::GentryAndDolly,
        LevelID::CommsRelay,
        true,
        false,
        false,
        {{-74, -16}, {-34, -16}, {6, -16}, {-125, -367},
            {-75, -367}, {-25, -367}, {26, -367}, {75, -367}, {126, -367},
            {175, -367},{226.125, -367},{275, -367},{326,-367}},
        {},
        {},
        {},
        {}
    };

    // CommsRelay
    levelMap[LevelID::CommsRelay] = LevelData{
        "11.CommsRelay",
        "11.CommsRelayBackground",
        LevelID::CommsRelay,
        LevelID::CommsRelay,
        LevelID::GentryAndDolly,
        LevelID::CommsRelay,
        false,
        false,
        false,
        {},
        {},
        {},
        {},
        {}
    };

    // TheYesMen
    levelMap[LevelID::TheYesMen] = LevelData{
        "12.TheYesMen",
        "12.TheYesMenBackground",
        LevelID::GentryAndDolly,
        LevelID::StopAndReflect,
        LevelID::TheYesMen,
        LevelID::TheYesMen,
        false,
        true,
        true,
        {},
        {},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {-117, 385}, {-117, 148}, {83, 83}, false, 5.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {-117, -122}, {-117, -356}, {83, 83}, true, 5.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {460, 385}, {460, -225}, {83, 83}, false,5.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {176, 269}, {176, 70}, {83, 83}, false, 7.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {176, -245}, {176, -50}, {83, 83}, false, 7.0f}},
        {{-352, 126}},
        {{-352, -94}}
    };

    // StopAndReflect
    levelMap[LevelID::StopAndReflect] = LevelData{
        "13.StopAndReflect",
        "13.StopAndReflectBackground",
        LevelID::TheYesMen,
        LevelID::VStitch,
        LevelID::StopAndReflect,
        LevelID::TrenchWarfare,
        true,
        false,
        true,
        {{-228, -241}, {-188, -241}},
        {{-228, 270}, {-188, 270}},
        {},
        {{540, -192}},
        {}
    };

    // TrenchWarfare
    levelMap[LevelID::TrenchWarfare] = LevelData{
        "14.TrenchWarfare",
        "14.TrenchWarfareBackground",
        LevelID::TrenchWarfare,
        LevelID::TrenchWarfare,
        LevelID::StopAndReflect,
        LevelID::TrenchWarfare,
        true,
        true,
        false,
        {},
        {{-435, 175}, {-400, 175},{-85, 175},{-50, 175},{210, 175},{240, 175},
            {-367, 363}, {-332, 363},{-297, 363},{-262, 363},{-227, 363},{-192, 363},{-157, 363}, {-122, 363},
            {-3, 363}, {33, 363},{69, 363},{105, 363},{141, 363},{177, 363},
            {273, 363}, {308, 363},{343, 363},{378, 363},{413, 363},{448, 363},{483, 363}, {518, 363}},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/14.enemy.png",   {-180, -350}, {-180, -100}, {70, 76}, true, 7.0f},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/14.enemy.png",   {75, -350}, {75, -100}, {70, 76}, false, 7.0f},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/14.enemy.png",   {335, -350}, {335, -100}, {70, 76}, true, 7.0f}},
        {},
        {}
    };

    // VStitch
    levelMap[LevelID::VStitch] = LevelData{
        "15.VStitch",
        "15.VStitchBackground",
        LevelID::StopAndReflect,
        LevelID::VStitch,
        LevelID::VStitch,
        LevelID::BBBBusted,
        true,
        false,
        true,
        {{20, 80}, {60, 80}, {100, 80},
            {405, 80}, {445, 80}, {485, 80},{525, 80}, {565, 80}, {605, 80},
            {-495, -365}, {-455, -365}, {-415, -365},
            {-235, -365}, {-195, -365}, {-155, -365},
            {25, -365}, {65, -365}, {105, -365},
            {285, -365}, {325, -365}, {365, -365}},
            {{-172, 395}, {-132, 395}, {-92, 395},
            {212, 395}, {252, 395}, {292, 395},
            {405, -55}, {445, -55}, {485, -55},{525, -55}, {565, -55}, {605, -55},
            {-530, -55},{-570, -55},{-610, -55},
            {-275, -55}, {-315, -55}, {-355, -55},
            {-105, -55}, {-65, -55}, {-25, -55},
            {150, -55}, {190, -55}, {230, -55}},
        {},
        {{-353, 125}},
        {}
    };

    // BBBBusted
    levelMap[LevelID::BBBBusted] = LevelData{
        "16.BBBBusted",
        "16.BBBBustedBackground",
        LevelID::BBBBusted,
        LevelID::BBBBusted,
        LevelID::VStitch,
        LevelID::TheSensibleRoom,
        true,
        true,
        false,
        {{-623, 75}, {-583, 75}, {-543, 75}, {-503, 75},
            {-463, 75},{-423, 75},{-383, 75}, {-343, 75},
            {-303, 75}, {-263, 75},
            {272, 75}, {312, 75}, {352, 75}, {392, 75},
            {432, 75}, {472, 75}, {512, 75}, {552, 75},
            {592, 75}, {632, 75}},
        {{-623, -48}, {-583, -48}, {-543, -48}, {-503, -48},
            {-463, -48},{-423, -48},{-383, -48}, {-343, -48},
            {-303, -48}, {-263, -48},{-223, -48},{-183, -48},
            {-143, -48}, {-103, -48}, {-63, -48},
            {72, -48}, {112, -48}, {152, -48},{192, -48}, {232, -48},
            {272, -48}, {312, -48}, {352, -48}, {392, -48},{432, -48},
            {472, -48}, {512, -48}, {552, -48},{592, -48}, {632, -48}},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/16.enemy.png",   {-640, 290}, {640, 290}, {257, 184}, true, 10.0f, true}},
        {},
        {}
    };

    // TheSensibleRoom
    levelMap[LevelID::TheSensibleRoom] = LevelData{
        "17.TheSensibleRoom",
        "17.TheSensibleRoomBackground",
        LevelID::BooThinkFast,
        LevelID::TheSensibleRoom,
        LevelID::BBBBusted,
        LevelID::TheSensibleRoom,
        true,
        false,
        true,
        {{-623, 75}, {-583, 75}, {-543, 75}, {-503, 75},
            {-463, 75}, {-423, 75}, {-383, 75}, {-343, 75},
            {-303, 75}, {-263, 75}, {-223, 75}, {-183, 75},
            {-143, 75}},
        {{-623, -50}, {-583, -50}, {-543, -50}, {-503, -50},
            {-462, -50}, {-303, -50}, {-263, -50}},
        {},
        {{0, 125}},
        {{-387, -130}}
    };

    // BooThinkFast
    levelMap[LevelID::BooThinkFast] = LevelData{
        "18.BooThinkFast",
        "18.BooThinkFastBackground",
        LevelID::BooThinkFast,
        LevelID::TheSensibleRoom,
        LevelID::BooThinkFast,
        LevelID::Driller,
        true,
        false,
        false,
        {{157, -110}, {197, -110}, {237, -110}, {277, -110},
            {317, -110}, {357, -110}, {397, -110}, {437, -110},
            {477, -110}, {517, -110}, {557, -110}, {597, -110},
            {637, -110}},
        {},
        {},
        {},
        {}
    };

    // Driller
    levelMap[LevelID::Driller] = LevelData{
        "19.Driller",
        "19.DrillerBackground",
        LevelID::Driller,
        LevelID::ExhaustChute,
        LevelID::BooThinkFast,
        LevelID::Quicksand,
        true,
        false,
        true,
        {{-608, -110}, {-568, -110}, {-528, -110}, {-488, -110},
            {-448, -110}, {-408, -110}, {-368, -110}, {-328, -110},
            {-288, -110}, {-248, -110}, {-208, -110}, {-168, -110},
            {-128, -110}, {-88, -110},  {85, -110}, {125, -110},
            {165, -110}, {205, -110}, {245, -110}, {285, -110},
            {325, -110}, {365, -110}, {405, -110}, {445, -110},
            {485, -110}, {525, -110}, {565, -110}, {605, -110}},
            {{-63, 360}, {-23, 360},{17, 360}, {57, 360}},
        {},
        {},
        {{-450, 350}, {440, 350}}
    };

    // ExhaustChute
    levelMap[LevelID::ExhaustChute] = LevelData{
        "20.ExhaustChute",
        "20.ExhaustChuteBackground",
        LevelID::Driller,
        LevelID::Sorrow,
        LevelID::ExhaustChute,
        LevelID::ExhaustChute,
        true,
        false,
        false,
        {{-300, 142},{-260, 142}, {-220, 142}, {-180, 142},
            {-40, 15},{4, 15}, {44, 15},
            {185, 142}, {225, 142}, {265, 142},{305, 142}},
            {{-488, 330},{-448, 330}, {-408, 330}, {-368, 330}, {-328, 330},
            {-288, 330}, {-248, 330}, {-208, 330}, {-168, 330},{-128, 330},
            {-88, 330},  {85, 330}, {125, 330},{165, 330},{205, 330},
            {245, 330}, {285, 330},{325, 330},{365, 330},{405, 330},
            {445, 330},{485, 330},{525, 330}, {565, 330},
            {-40, -80},{4, -80}, {44, -80}},
        {},
        {},
        {}
    };

    // Sorrow
    levelMap[LevelID::Sorrow] = LevelData{
        "21.Sorrow",
        "21.SorrowBackground",
        LevelID::ExhaustChute,
        LevelID::Sorrow,
        LevelID::Sorrow,
        LevelID::Sorrow,
        true,
        false,
        false,
        {{-152, 303}, {-112, 303},
            {108, 303}, {145, 303},
            {-118, 145}, {-78, 145},
            {80, 145}, {118, 145}},
        {{-152, 237}, {-112, 237},
            {108, 237}, {145, 237},
            {-118, 77}, {-75, 77},
            {80, 77}, {118, 77}},
        {},
        {},
        {}
    };

    // Quicksand
    levelMap[LevelID::Quicksand] = LevelData{
        "22.Quicksand",
        "22.QuicksandBackground",
        LevelID::Quicksand,
        LevelID::TheTombOfMadCarew,
        LevelID::Driller,
        LevelID::Quicksand,
        true,
        false,
        false,
        {},
        {},
        {},
        {},
        {}
    };

    // TheTombOfMadCarew
    levelMap[LevelID::TheTombOfMadCarew] = LevelData{
        "23.TheTombOfMadCarew",
        "23.TheTombOfMadCarewBackground",
        LevelID::Quicksand,
        LevelID::TheTombOfMadCarew,
        LevelID::TheTombOfMadCarew,
        LevelID::BrassSentUsUnderTheTop,
        true,
        false,
        false,
        {},
        {},
        {},
        {},
        {}
    };

    // BrassSentUsUnderTheTop
    levelMap[LevelID::BrassSentUsUnderTheTop] = LevelData{
        "24.BrassSentUsUnderTheTop",
        "24.BrassSentUsUnderTheTopBackground",
        LevelID::BrassSentUsUnderTheTop,
        LevelID::BrassSentUsUnderTheTop,
        LevelID::TheTombOfMadCarew,
        LevelID::AWrinkleInTime,
        true,
        false,
        false,
        {},
        {},
        {},
        {},
        {}
    };

    // AWrinkleInTime
    levelMap[LevelID::AWrinkleInTime] = LevelData{
        "25.AWrinkleInTime",
        "25.AWrinkleInTimeBackground",
        LevelID::AWrinkleInTime,
        LevelID::AWrinkleInTime,
        LevelID::BrassSentUsUnderTheTop,
        LevelID::AWrinkleInTime,
        true,
        false,
        false,
        {},
        {},
        {},
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
