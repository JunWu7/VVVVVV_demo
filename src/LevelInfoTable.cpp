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
        {{-30, -225}},
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
        false,
        true,
        {},
        {},
        {},
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
        false,
        {{-70, -303}, {-25, -303}, {20, -303}, {65, -303}, {110, -303},{155, -303}},
        {{-300, 360},{-253.125, 360},{-206.25, 360},{-159.375,360},{-112.5, 360},
            {-65.625, 360},{-18.75, 360},{28.125, 360},{75, 360}},
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
        false,
        {{-430, -175},{-390, -175},{-350, -175},{-140, -175},
            {-100, -175},{-60, -175},{-20, -175},{20, -175},{60, -175}},
        {{-300, 136},{-255, 136},{-210, 136},{-165, 136},{-120, 136},{80, 136}, {125, 136}, {170, 136}},
        {},
        {},
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
        true,
        false,
        false,
        {},
        {},
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
        true,
        false,
        false,
        {},
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
        {},
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
        true,
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
        true,
        false,
        false,
        {},
        {},
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
        false,
        {},
        {},
        {},
        {},
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
        false,
        false,
        {},
        {},
        {},
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
        false,
        {},
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
        false,
        false,
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
        false,
        {},
        {},
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
        {},
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
        false,
        {},
        {},
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
