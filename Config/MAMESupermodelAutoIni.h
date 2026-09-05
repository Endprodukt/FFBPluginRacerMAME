#pragma once

#include <Windows.h>
#include <cstring>
#include <string>

// MAME/Supermodel-only configuration bootstrap.
// Creates a complete, grouped FFBPlugin.ini when none exists.
// Existing INIs are never overwritten.
namespace MAMESupermodelAutoIni
{
    static const wchar_t* const kIniPath = L".\\FFBPlugin.ini";

struct GameProfile
{
    const char* name;
    int minForce;
    int maxForce;
    int altMinLeft;
    int altMaxLeft;
    int altMinRight;
    int altMaxRight;
    int feedbackLength;
    int powerMode;
    int springEnable;
    int springStrength;
    int damperEnable;
    int damperStrength;
};

struct ExtraSetting
{
    const char* game;
    const char* key;
    int value;
};

inline void AppendSetting(std::string& ini, const char* key, int value)
{
    ini += key;
    ini += '=';
    ini += std::to_string(value);
    ini += "\r\n";
}

inline void AppendGameSetting(std::string& ini, const char* prefix, const char* game, int value)
{
    ini += prefix;
    ini += game;
    ini += '=';
    ini += std::to_string(value);
    ini += "\r\n";
}

inline std::string BuildDefaultIni()
{
    std::string ini;
    ini.reserve(20000);

    ini += "; *******************************************\r\n";
    ini += "; *** FFB Settings for MAME 64bit Outputs ***\r\n";
    ini += "; *******************************************\r\n";
    ini += "[Settings]\r\n";
    ini += "StartDelay=0\r\n";
    ini += "GameId=22\r\n";
    ini += "MinForce=0\r\n";
    ini += "MaxForce=100\r\n";
    ini += "DeviceGUID=\r\n";
    ini += "EnableRumble=1\r\n";
    ini += "ReverseRumble=0\r\n";
    ini += "EnableRumbleTriggers=1\r\n";
    ini += "Logging=0\r\n";
    ini += "FeedbackLength=500\r\n";
    ini += "DefaultCentering=0\r\n";
    ini += "DefaultFriction=0\r\n";
    ini += "BeepWhenHook=0\r\n";
    ini += "AlternativeFFB=0\r\n";
    ini += "AlternativeMinForceLeft=0\r\n";
    ini += "AlternativeMaxForceLeft=-100\r\n";
    ini += "AlternativeMinForceRight=0\r\n";
    ini += "AlternativeMaxForceRight=100\r\n";
    ini += "ForceShowDeviceGUIDMessageBox=0\r\n";
    ini += "EnableFFBStrengthDynamicAdjustment=0\r\n";
    ini += "IncreaseFFBStrength=99\r\n";
    ini += "DecreaseFFBStrength=99\r\n";
    ini += "ResetFFBStrength=99\r\n";
    ini += "StepFFBStrength=10\r\n";
    ini += "IncreaseFFBStrengthKey=\r\n";
    ini += "DecreaseFFBStrengthKey=\r\n";
    ini += "ResetFFBStrengthKey=\r\n";
    ini += "EnableFFBStrengthPersistence=0\r\n";
    ini += "EnableFFBStrengthTextToSpeech=0\r\n";
    ini += "AutoScrollGUI=0\r\n";
    ini += "IgnoreFirstMatchingGUID=0\r\n";
    ini += "EnableForceSpringEffect=0\r\n";
    ini += "ForceSpringStrength=100\r\n";
    ini += "Device2GUID=\r\n";
    ini += "EnableRumbleDevice2=1\r\n";
    ini += "ReverseRumbleDevice2=0\r\n";
    ini += "AlternativeFFBDevice2=0\r\n";
    ini += "Device3GUID=\r\n";
    ini += "EnableRumbleDevice3=1\r\n";
    ini += "ReverseRumbleDevice3=0\r\n";
    ini += "AlternativeFFBDevice3=0\r\n";
    ini += "UseConstantInf=1\r\n";

    static const GameProfile games[] =
    {
        {"AceDriver", 0, 46, 0, -30, 0, 30, 500, 0, 0, 50, 0, 50},
        {"AceDriverVictory", 0, 45, 0, -30, 0, 30, 500, 0, 0, 50, 0, 50},
        {"CBombers", 0, 30, 0, -30, 0, 30, 500, 0, 1, 50, 0, 90},
        {"CalSpeed", 0, 50, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"CartFury", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"CisHeat", 0, 30, 0, -30, 0, 30, 500, 0, 1, 60, 0, 90},
        {"CrusnUSA", 0, 30, 0, -30, 0, 30, 500, 1, 0, 50, 0, 90},
        {"CrusnWld", 0, 45, 0, -30, 0, 30, 500, 1, 0, 50, 0, 90},
        {"CrusnExotica", 0, 45, 0, 100, 0, 100, 120, 0, 0, 0, 0, 100},
        {"DAxle", 0, 43, 0, -30, 0, 30, 500, 0, 1, 50, 0, 90},
        {"Daytona", 0, 60, 0, -30, 0, 30, 500, 0, 1, 50, 0, 90},
        {"DirtDash", 0, 40, 0, -30, 0, 30, 500, 1, 0, 50, 1, 15},
        {"DriversEdge", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 20},
        {"F1GpStar", 0, 57, 0, -30, 0, 30, 500, 0, 1, 50, 0, 90},
        {"F1GpStar2", 0, 30, 0, -30, 0, 30, 500, 0, 1, 50, 0, 90},
        {"GTIClub", 0, 42, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"HardD", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"HyperDrive", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"Indy500", 0, 55, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"MidnRun", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"ORunners", 0, 30, 0, -30, 0, 30, 500, 0, 1, 50, 0, 90},
        {"OffRoadC", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"Outrun", 0, 30, 0, -30, 0, 30, 500, 0, 1, 70, 0, 90},
        {"OverRev", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"PDrift", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"RacingJ", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"RacingJ2", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"RaveRacer", 0, 50, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"RoadEdge", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"SFRush", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"SFRush2049", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"SFRushRock", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"SideBS", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"SideBS2", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"SpeedUp", 0, 50, 0, -100, 0, 100, 500, 0, 0, 50, 0, 90},
        {"SRally", 0, 42, 0, -30, 0, 30, 500, 0, 1, 40, 0, 90},
        {"STCC", 0, 19, 0, 1, 0, 1, 500, 0, 0, 50, 0, 90},
        {"SuperChase", 0, 100, -100, 100, -100, 100, 500, 0, 0, 50, 0, 90},
        {"SuperGT", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"SuperMonacoGP", 0, 20, 0, -100, 0, 100, 284, 0, 1, 60, 0, 90},
        {"TOutrun", 0, 30, 0, -30, 0, 30, 500, 0, 1, 50, 0, 90},
        {"ThrillD", 0, 50, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"VaporTrx", 0, 30, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"VirtuaRacing", 0, 50, 0, -30, 0, 30, 520, 0, 1, 50, 0, 90},
        {"Windheat", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
        {"Xrally", 0, 40, 0, -30, 0, 30, 500, 0, 0, 50, 0, 90},
    };

    static const ExtraSetting extras[] =
    {
        {"AceDriver", "FFBDivideAceDriver", 643},
        {"AceDriverVictory", "FFBDivideAceDriverVictory", 643},
        {"CBombers", "SinePeriodCBombers", 100},
        {"CBombers", "SineStrengthCBombers", 100},
        {"CBombers", "RumbleStrengthRightMotorCBombers", 100},
        {"CisHeat", "SineStrengthCisHeat", 100},
        {"CisHeat", "RumbleStrengthRightMotorCisHeat", 100},
        {"CisHeat", "SinePeriodCisHeat", 100},
        {"CrusnExotica", "FFBGainCrusnExotica", 400},
        {"DAxle", "SineFadePeriodDAxle", 0},
        {"DAxle", "SinePeriodDAxle", 100},
        {"DAxle", "SineStrengthDAxle", 100},
        {"DAxle", "RumbleStrengthRightMotorDAxle", 100},
        {"DirtDash", "FFBDivideDirtDash", 1913},
        {"F1GpStar", "SineFadePeriodF1GpStar", 0},
        {"F1GpStar", "SineStrengthF1GpStar", 100},
        {"F1GpStar", "SinePeriodF1GpStar", 100},
        {"F1GpStar2", "SinePeriodF1GpStar2", 100},
        {"F1GpStar2", "SineStrengthF1GpStar2", 100},
        {"F1GpStar2", "SineFadePeriodF1GpStar2", 0},
        {"ORunners", "SinePeriodORunners", 100},
        {"ORunners", "SineStrengthORunners", 100},
        {"ORunners", "RumbleStrengthLeftMotorORunners", 100},
        {"ORunners", "RumbleStrengthRightMotorORunners", 100},
        {"Outrun", "SinePeriodOutrun", 100},
        {"Outrun", "SineStrengthOutrun", 100},
        {"Outrun", "RumbleStrengthRightMotorOutrun", 100},
        {"Outrun", "RumbleStrengthLeftMotorOutrun", 100},
        {"PDrift", "SinePeriodPDrift", 100},
        {"PDrift", "SineStrengthPDrift", 100},
        {"PDrift", "RumbleStrengthLeftMotorPDrift", 100},
        {"PDrift", "RumbleStrengthRightMotorPDrift", 100},
        {"RaveRacer", "ReverseDirection", 0},
        {"SuperMonacoGP", "SinePeriodSuperMonacoGP", 150},
        {"SuperMonacoGP", "SineFadePeriodSuperMonacoGP", 0},
        {"SuperMonacoGP", "SineStrengthSuperMonacoGP", 100},
        {"TOutrun", "SinePeriodTOutrun", 100},
        {"TOutrun", "SineStrengthTOutrun", 100},
        {"TOutrun", "RumbleStrengthRightMotorTOutrun", 100},
        {"TOutrun", "RumbleStrengthLeftMotorTOutrun", 100},
    };

    for (const GameProfile& game : games)
    {
        ini += "\r\n; ---- ";
        ini += game.name;
        ini += " ----\r\n";

        AppendGameSetting(ini, "MinForce", game.name, game.minForce);
        AppendGameSetting(ini, "MaxForce", game.name, game.maxForce);
        AppendGameSetting(ini, "AlternativeMinForceLeft", game.name, game.altMinLeft);
        AppendGameSetting(ini, "AlternativeMaxForceLeft", game.name, game.altMaxLeft);
        AppendGameSetting(ini, "AlternativeMinForceRight", game.name, game.altMinRight);
        AppendGameSetting(ini, "AlternativeMaxForceRight", game.name, game.altMaxRight);
        AppendGameSetting(ini, "FeedbackLength", game.name, game.feedbackLength);
        AppendGameSetting(ini, "PowerMode", game.name, game.powerMode);
        AppendGameSetting(ini, "EnableForceSpringEffect", game.name, game.springEnable);
        AppendGameSetting(ini, "ForceSpringStrength", game.name, game.springStrength);
        AppendGameSetting(ini, "EnableDamper", game.name, game.damperEnable);
        AppendGameSetting(ini, "DamperStrength", game.name, game.damperStrength);

        for (const ExtraSetting& extra : extras)
        {
            if (std::strcmp(extra.game, game.name) == 0)
                AppendSetting(ini, extra.key, extra.value);
        }
    }

    return ini;
}

inline void EnsureIniExists()
{
    const DWORD attributes = GetFileAttributesW(kIniPath);
    if (attributes != INVALID_FILE_ATTRIBUTES)
        return;

    const std::string ini = BuildDefaultIni();

    HANDLE file = CreateFileW(
        kIniPath,
        GENERIC_WRITE,
        FILE_SHARE_READ,
        nullptr,
        CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);

    if (file == INVALID_HANDLE_VALUE)
        return;

    DWORD bytesWritten = 0;
    WriteFile(
        file,
        ini.data(),
        static_cast<DWORD>(ini.size()),
        &bytesWritten,
        nullptr);
    CloseHandle(file);
}

inline UINT ReadPrivateProfileInt(
    LPCWSTR section,
    LPCWSTR key,
    INT defaultValue,
    LPCWSTR fileName)
{
    if (fileName && lstrcmpiW(fileName, kIniPath) == 0)
        EnsureIniExists();

    return GetPrivateProfileIntW(section, key, defaultValue, fileName);
}
}

// DllMain.cpp and MAMESupermodel.cpp both include MAMESupermodel.h before
// reading their integer settings. Redirect those reads through the bootstrap,
// so GameId=22 exists on the first launch.
#ifdef GetPrivateProfileInt
#undef GetPrivateProfileInt
#endif
#define GetPrivateProfileInt MAMESupermodelAutoIni::ReadPrivateProfileInt
