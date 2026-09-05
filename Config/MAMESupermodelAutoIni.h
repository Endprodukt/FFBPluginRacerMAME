#pragma once

#include <Windows.h>
#include <string>
#include <cstring>

// MAME configuration bootstrap.
// Creates one complete, grouped FFBPlugin.ini when none exists.
// Existing INIs are never overwritten.
namespace MAMESupermodelAutoIni
{
    static const wchar_t* const kIniPath = L".\\FFBPlugin.ini";

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

    inline void AppendGameSetting(std::string& ini, const char* key, const char* game, int value)
    {
        ini += key;
        ini += game;
        ini += '=';
        ini += std::to_string(value);
        ini += "\r\n";
    }

    inline std::string BuildDefaultIni()
    {
        std::string ini;
        ini.reserve(22000);

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
        ini += "ForceSpringStrength=0\r\n";
        ini += "Device2GUID=\r\n";
        ini += "EnableRumbleDevice2=1\r\n";
        ini += "ReverseRumbleDevice2=0\r\n";
        ini += "AlternativeFFBDevice2=0\r\n";
        ini += "Device3GUID=\r\n";
        ini += "EnableRumbleDevice3=1\r\n";
        ini += "ReverseRumbleDevice3=0\r\n";
        ini += "AlternativeFFBDevice3=0\r\n";
        ini += "UseConstantInf=1\r\n";

        static const char* games[] =
        {
        "AceDriver",
        "AceDriverVictory",
        "CBombers",
        "CalSpeed",
        "CartFury",
        "CisHeat",
        "CrusnUSA",
        "CrusnWld",
        "CrusnExotica",
        "DAxle",
        "Daytona",
        "DirtDash",
        "DriversEdge",
        "F1GpStar",
        "F1GpStar2",
        "GTIClub",
        "HardD",
        "HyperDrive",
        "Indy500",
        "MidnRun",
        "ORunners",
        "OffRoadC",
        "Outrun",
        "OverRev",
        "PDrift",
        "RacingJ",
        "RacingJ2",
        "RaveRacer",
        "RoadEdge",
        "SFRush",
        "SFRush2049",
        "SFRushRock",
        "SideBS",
        "SideBS2",
        "SpeedUp",
        "SRally",
        "STCC",
        "SuperChase",
        "SuperGT",
        "SuperMonacoGP",
        "TOutrun",
        "ThrillD",
        "VaporTrx",
        "VirtuaRacing",
        "Windheat",
        "Xrally"
        };

        static const ExtraSetting extras[] =
        {
        {"AceDriver", "FFBDivideAceDriver", 643},
        {"AceDriverVictory", "FFBDivideAceDriverVictory", 643},
        {"CBombers", "SinePeriodCBombers", 100},
        {"CBombers", "SineStrengthCBombers", 100},
        {"CBombers", "RumbleStrengthRightMotorCBombers", 100},
        {"CisHeat", "SinePeriodCisHeat", 100},
        {"CisHeat", "SineStrengthCisHeat", 100},
        {"CisHeat", "RumbleStrengthRightMotorCisHeat", 100},
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
        {"SuperMonacoGP", "SinePeriodSuperMonacoGP", 100},
        {"SuperMonacoGP", "SineFadePeriodSuperMonacoGP", 0},
        {"SuperMonacoGP", "SineStrengthSuperMonacoGP", 100},
        {"TOutrun", "SinePeriodTOutrun", 100},
        {"TOutrun", "SineStrengthTOutrun", 100},
        {"TOutrun", "RumbleStrengthRightMotorTOutrun", 100},
        {"TOutrun", "RumbleStrengthLeftMotorTOutrun", 100}
        };

        for (const char* game : games)
        {
            ini += "\r\n; ---- ";
            ini += game;
            ini += " ----\r\n";

            // Neutral per-game defaults. These are deliberately not copied
            // from a user's tuned INI.
            AppendGameSetting(ini, "MinForce", game, 0);
            AppendGameSetting(ini, "MaxForce", game, 100);
            AppendGameSetting(ini, "AlternativeMinForceLeft", game, 0);
            AppendGameSetting(ini, "AlternativeMaxForceLeft", game, -100);
            AppendGameSetting(ini, "AlternativeMinForceRight", game, 0);
            AppendGameSetting(ini, "AlternativeMaxForceRight", game, 100);
            AppendGameSetting(ini, "FeedbackLength", game, 500);
            AppendGameSetting(ini, "PowerMode", game, 0);
            AppendGameSetting(ini, "EnableForceSpringEffect", game, 0);
            AppendGameSetting(ini, "ForceSpringStrength", game, 0);
            AppendGameSetting(ini, "EnableDamper", game, 0);
            AppendGameSetting(ini, "DamperStrength", game, 100);

            for (const ExtraSetting& extra : extras)
            {
                if (std::strcmp(extra.game, game) == 0)
                    AppendSetting(ini, extra.key, extra.value);
            }
        }

        return ini;
    }

    inline void EnsureIniExists()
    {
        if (GetFileAttributesW(kIniPath) != INVALID_FILE_ATTRIBUTES)
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
        WriteFile(file, ini.data(), static_cast<DWORD>(ini.size()), &bytesWritten, nullptr);
        CloseHandle(file);
    }

    inline UINT ReadPrivateProfileInt(
        LPCWSTR section,
        LPCWSTR key,
        INT defaultValue,
        LPCWSTR fileName)
    {
        const bool isOurIni = fileName && lstrcmpiW(fileName, kIniPath) == 0;
        const bool isSettings = section && lstrcmpiW(section, L"Settings") == 0;

        if (isOurIni && isSettings)
            EnsureIniExists();

        if (isOurIni && isSettings && key && wcscmp(key, L"GameId") == 0)
            defaultValue = 22;

        return GetPrivateProfileIntW(section, key, defaultValue, fileName);
    }
}

#ifdef GetPrivateProfileInt
#undef GetPrivateProfileInt
#endif
#define GetPrivateProfileInt MAMESupermodelAutoIni::ReadPrivateProfileInt
