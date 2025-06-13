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
        true,
        false,
        false,
        {},                                 // 無陷阱位置
        {},
        {},
        {},
        {},
        {},
        {},
        {}
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
        false,
        false,
        false,
        {{-201, -303}, {-151, -303}, {-101, -303}, {-51, -303},{-1, -303},
            {49, -303}, {99, -303}, {149, -303}, {199, -303}},
        {},
        {},
        {},
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
        false,
        false,
        false,
        {},
        {},
        {},
        {{-30, -227}},
        {},
        {},
        {},
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
        false,
        false,
        false,
        {},
        {},
        {},
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
        false,
        false,
        false,
        {},
        {},
        {
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/5.enemy.png",   {220, -80}, {220, 210}, {90, 130}, true, 10.0f},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/5.enemy.png",   {-100, 85}, {-100, 375}, {90, 130}, false, 10.0f},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/5.enemy.png",   {-415, -80}, {-415, 210}, {90, 130}, true, 10.0f}},
        {},
        {{317.5, -287.5}},
        {},
        {},
        {}
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
        false,
        false,
        false,
        {{-70, -303}, {-25, -303}, {20, -303}, {65, -303}, {110, -303},{155, -303}},
        {{-300, 360},{-253.125, 360},{-206.25, 360},{-159.375,360},{-112.5, 360},
            {-65.625, 360},{-18.75, 360},{28.125, 360},{75, 360}},
        {},
        {{-165, -195}},
        {{160, 255}},
        {},
        {},
        {}
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
        false,
        false,
        true,
        {{-430, -175},{-390, -175},{-350, -175},{-140, -175},
            {-100, -175},{-60, -175},{-20, -175},{20, -175},{60, -175}},
        {{-300, 136},{-255, 136},{-210, 136},{-165, 136},{-120, 136},{80, 136}, {125, 136}, {170, 136}},
        {},
        {{255, -130}},
        {},
        {},
        {},
        {{-545, -120}}
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
        false,
        false,
        false,
        {},
        {},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/8.enemy.png",   {-290, 100}, {290, 100}, {128, 66}, true, 4.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/8.enemy.png",   {-290, -62}, {290, -62}, {128, 66}, false, 4.0f}},
        {{-513, -225}},
        {{510, 255}},
        {},
        {},
        {}
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
        false,
        false,
        false,
        {},
        {},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/9.point.png",   {186, 345}, {186, -214}, {67, 67}, false, 15.0f}},
        {{62, 25}},
        {},
        {},
        {},
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
        true,
        true,
        false,
        {{-74, -16}, {-34, -16}, {6, -16}, {-115, -367},
            {-75, -367}, {-25, -367}, {26, -367}, {75, -367}, {126, -367},
            {175, -367},{226.125, -367},{275, -367},{316,-367}},
        {{-235, 263}, {-195, 263}, {-155, 263}, {-115, 263},
            {-75, 263}, {-35, 263}, {5, 263}, {45, 263}, {85, 263},
            {125, 263}, {165, 263},
            {-426, -119.5},{-386, -119.5}, {-346, -119.5}, {-306, -119.5},
            {-266, -119.5}, {-226, -119.5}, {-186, -119.5}, {-146, -119.5},
            {-106, -119.5}, {-66, -119.5}, {-26, -119.5}, {14, -119.5},
            {54, -119.5}, {94, -119.5}, {134, -119.5}, {174, -119.5},
            {214, -119.5}, {254, -119.5}, {294, -119.5}, {334, -119.5}},
        {},
        {},
        {},
        {{{-161.5, 225}, "red"}, {{-33.5, 225}, "red"}, {{94.5, 225}, "red"}},
        {{"10.GentryAndDollyMP", {-386, -165}, {318, -165}, {-386, -165}, {124, 31}, 10, false, true}},
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
        false,
        false,
        false,
        {},
        {},
        {},
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
        false,
        false,
        false,
        {},
        {},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {-117, 385}, {-117, 148}, {83, 83}, false, 5.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {-117, -122}, {-117, -356}, {83, 83}, true, 5.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {460, 385}, {460, -225}, {83, 83}, false,5.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {176, 269}, {176, 70}, {83, 83}, false, 7.0f},
        {std::string(GA_RESOURCE_DIR) + "/Image/Background/12.yesman.png",   {176, -245}, {176, -50}, {83, 83}, false, 7.0f}},
        {{-352, 126}},
        {{-352, -94}},
        {},
        {},
        {}
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
        false,
        true,
        false,
        {{-228, -241}, {-188, -241},
        {-134, -395}, {-94, -395}, {-54, -395}, {-14, -395},
        {26, -395}, {66, -395}, {106, -395}, {146, -395}, {186, -395},
        {226, -395}, {266, -395}, {306, -395}, {346, -395}, {386, -395},
        {426, -395}, {466, -395}},
        {{-228, 270}, {-188, 270},
        {-134, 424}, {-94, 424}, {-54, 424}, {-14, 424},
        {26, 424}, {66, 424}, {106, 424}, {146, 424}, {186, 424},
        {226, 424}, {266, 424}, {306, 424}, {346, 424}, {386, 424},
        {426, 424}, {466, 424}},
        {},
        {{540, -192}},
        {},
        {},
        {{"13.StopAndReflectMP", {-41, -154.5}, {-41, 199.5}, {-41, 199.5}, {140, 35}, 5, true, false},
        {"13.StopAndReflectMP", {159, -154.5}, {159, 199.5}, {159, 22.5}, {140, 35}, 5, true, true},
        {"13.StopAndReflectMP",  {359, -154.5}, {359, 199.5}, {359, -154.5}, {140, 35}, 5, true, true}},
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
        false,
        true,
        true,
        {},
        {{-420, 170}, {-70, 170},{-55, 170},{215, 170},{230, 170},
            {-367, 363}, {-332, 363},{-297, 363},{-262, 363},{-227, 363},{-192, 363},{-157, 363}, {-122, 363},
            {-3, 363}, {33, 363},{69, 363},{105, 363},{141, 363},{177, 363},
            {273, 363}, {308, 363},{343, 363},{378, 363},{413, 363},{448, 363},{483, 363}, {518, 363}},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/14.enemy.png",   {-180, -350}, {-180, -100}, {70, 76}, true, 12.0f},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/14.enemy.png",   {75, -350}, {75, -100}, {70, 76}, false, 12.0f},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/14.enemy.png",   {335, -350}, {335, -100}, {70, 76}, true, 12.0f}},
        {},
        {},
        {},
        {{"14.TrenchWarfareWP", {-327.5, 268}, {482.5, 268}, {-327.5, 268}, {115, 30}, 10, false, true}},
        {{475, -165}}
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
        false,
        false,
        false,
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
        {},
        {},
        {},
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
        false,
        false,
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
        {},
        {},
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
        false,
        false,
        false,
        {{-623, 75}, {-583, 75}, {-543, 75}, {-503, 75},
            {-463, 75}, {-423, 75}, {-383, 75}, {-343, 75},
            {-303, 75}, {-263, 75}, {-223, 75}, {-183, 75},
            {-143, 75}},
        {{-623, -50}, {-583, -50}, {-543, -50}, {-503, -50},
            {-462, -50}, {-303, -50}, {-263, -50}},
        {},
        {{0, 125}},
        {{-387, -130}},
        {},
        {},
        {}
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
        true,
        false,
        false,
        {{157, -110}, {197, -110}, {237, -110}, {277, -110},
            {317, -110}, {357, -110}, {397, -110}, {437, -110},
            {477, -110}, {517, -110}, {557, -110}, {597, -110},
            {637, -110}},
        {{-103.5, 360}, {-63.5, 360}, {-23.5, 360}, {16.5, 360},
            {56.5, 360}, {96.5, 360}, {136.5, 360}, {176.5, 360},
            {216.5, 360}, {256.5, 360}},
        {},
        {},
        {},
        {{{0, 300}, "green"}, {{224, -60}, "green"}},
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
        false,
        false,
        false,
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
        {{-450, 350}, {440, 350}},
        {},
        {},
        {}
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
        false,
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
        {},
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
        false,
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
        {},
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
        true,
        false,
        false,
        {{-615.5, -110}, {-575.5, -110}, {-535.5, -110}, {-495.5, -110},
            {-455.5, -110}, {-415.5, -110}, {-375.5, -110}, {-335.5, -110},
            {-295.5, -110}, {-255.5, -110},
            {-105.5, -80}, {-65.5, -80}, {-25.5, -80},
            {154.5, -80}, {194.5, -80}, {234.5, -80}},
        {{54.5, 395}, {94.5, 395}, {134.5, 395}, {174.5, 395},{214.5, 395}},
        {},
        {},
        {},
        {{{-64, 170}, ""}, {{64, 170}, ""}, {{192, 170}, ""},
        {{-64, 138}, ""}, {{64, 138}, ""}, {{192, 138}, ""},
        {{-64, 106}, ""}, {{64, 106}, ""}, {{192, 106}, ""},
        {{-64, 74}, ""}, {{64, 74}, ""}, {{192, 74}, ""},
        {{-64, 42}, ""}, {{64, 42}, ""}, {{192, 42}, ""},
        {{-64, 10}, ""}, {{64, 10}, ""}, {{192, 10}, ""}},
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
        true,
        true,
        false,
        false,
        false,
        {{60, -80}, {100, -80}, {140, -80}, {180, -80},
            {220, -80}, {260, -80}, {300, -80}, {340, -80},
            {380, -80}},
        {{100, 360},
        {340, 360}, {380, 360}, {420, 360}, {460, 360}, {500, 360}, {540, 360}, {580, 360}},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/23.enemy.png",   {220, 255}, {225, -15}, {100, 104}, false, 5.0f, false}},
        {{-55, 66}},
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
        true,
        false,
        false,
        false,
        false,
        {{-105, -80}, {-55, -80}, {-5, -80}, {45, -80},{95, -80}},
        {{-615.5, 365}, {-575.5, 365},
            {-360, 365}, {-320, 365}, {-280, 365}, {-240, 365}, {-200, 365},
            {575.5, 365}, {615.5, 365},
        {360, 365}, {320, 365}, {280, 365}, {240, 365}, {200, 365}},
        {{std::string(GA_RESOURCE_DIR) + "/Image/Background/24.enemy.png",   {-347, 223}, {347, 223}, {116, 124}, true, 8.0f, false},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/24.enemy.png",   {-347, 95}, {347, 95}, {116, 124}, false, 8.0f, false},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/24.enemy.png",   {-58, -288}, {582, -288}, {116, 124}, true, 8.0f, false},
            {std::string(GA_RESOURCE_DIR) + "/Image/Background/24.enemy.png",   {58, -288}, {-582, -288}, {116, 124}, true, 8.0f, false}},
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
        false,
        false,
        true,
        false,
        false,
        false,
        {},
        {},
        {},
        {{-322.5, -69.5}},
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
