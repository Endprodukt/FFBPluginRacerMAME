#pragma once

#include <Windows.h>
#include <string>
#include <cstring>
#include <vector>

// MAME configuration bootstrap.
// Creates one complete, grouped FFBPlugin.ini when none exists.
// Existing values are never overwritten. Missing settings/game blocks are
// restored from the current default template on startup.
namespace MAMESupermodelAutoIni
{
    static const wchar_t* const kIniPath = L".\\FFBPlugin.ini";

    struct ExtraSetting
    {
        const char* game;
        const char* key;
        int value;
    };

    struct MissingBlock
    {
        std::string marker;
        std::vector<std::string> lines;
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

    inline std::string Trim(const std::string& value)
    {
        size_t first = value.find_first_not_of(" \t\r\n");
        if (first == std::string::npos)
            return std::string();

        size_t last = value.find_last_not_of(" \t\r\n");
        return value.substr(first, last - first + 1);
    }

    inline std::string GetKeyFromLine(const std::string& line)
    {
        const std::string trimmed = Trim(line);
        if (trimmed.empty() || trimmed[0] == ';' || trimmed[0] == '[')
            return std::string();

        const size_t equals = trimmed.find('=');
        if (equals == std::string::npos)
            return std::string();

        return Trim(trimmed.substr(0, equals));
    }

    inline bool KeyExists(const std::string& ini, const std::string& wantedKey)
    {
        size_t pos = 0;
        while (pos <= ini.size())
        {
            const size_t end = ini.find('\n', pos);
            std::string line = ini.substr(pos, end == std::string::npos ? std::string::npos : end - pos);
            const std::string key = GetKeyFromLine(line);

            if (!key.empty() && lstrcmpiA(key.c_str(), wantedKey.c_str()) == 0)
                return true;

            if (end == std::string::npos)
                break;
            pos = end + 1;
        }
        return false;
    }

    inline bool HasSettingsSection(const std::string& ini)
    {
        size_t pos = 0;
        while (pos <= ini.size())
        {
            const size_t end = ini.find('\n', pos);
            const std::string line = Trim(ini.substr(pos, end == std::string::npos ? std::string::npos : end - pos));
            if (lstrcmpiA(line.c_str(), "[Settings]") == 0)
                return true;

            if (end == std::string::npos)
                break;
            pos = end + 1;
        }
        return false;
    }

    inline bool ReadIni(std::string& ini)
    {
        HANDLE file = CreateFileW(
            kIniPath,
            GENERIC_READ,
            FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
            nullptr,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            nullptr);

        if (file == INVALID_HANDLE_VALUE)
            return false;

        LARGE_INTEGER size = {};
        if (!GetFileSizeEx(file, &size) || size.QuadPart < 0 || size.QuadPart > 4 * 1024 * 1024)
        {
            CloseHandle(file);
            return false;
        }

        ini.resize(static_cast<size_t>(size.QuadPart));
        DWORD bytesRead = 0;
        const BOOL ok = ini.empty() || ReadFile(file, &ini[0], static_cast<DWORD>(ini.size()), &bytesRead, nullptr);
        CloseHandle(file);

        if (!ok)
            return false;

        ini.resize(bytesRead);
        return true;
    }

    inline bool WriteIni(const std::string& ini, DWORD creationDisposition)
    {
        HANDLE file = CreateFileW(
            kIniPath,
            GENERIC_WRITE,
            FILE_SHARE_READ,
            nullptr,
            creationDisposition,
            FILE_ATTRIBUTE_NORMAL,
            nullptr);

        if (file == INVALID_HANDLE_VALUE)
            return false;

        DWORD bytesWritten = 0;
        const BOOL ok = ini.empty() || WriteFile(file, ini.data(), static_cast<DWORD>(ini.size()), &bytesWritten, nullptr);
        CloseHandle(file);
        return ok && bytesWritten == ini.size();
    }

    inline std::string JoinLines(const std::vector<std::string>& lines)
    {
        std::string result;
        for (const std::string& line : lines)
        {
            result += line;
            result += "\r\n";
        }
        return result;
    }

    inline std::string MergeMissingSettings(const std::string& currentIni, const std::string& defaultIni)
    {
        if (currentIni.empty())
            return defaultIni;

        if (!HasSettingsSection(currentIni))
        {
            std::string merged = currentIni;
            if (!merged.empty() && merged.back() != '\n')
                merged += "\r\n";
            merged += "\r\n";
            merged += defaultIni;
            return merged;
        }

        std::vector<std::string> missingGlobals;
        std::vector<MissingBlock> blocks;
        MissingBlock* currentBlock = nullptr;

        size_t pos = 0;
        while (pos <= defaultIni.size())
        {
            const size_t end = defaultIni.find('\n', pos);
            std::string line = defaultIni.substr(pos, end == std::string::npos ? std::string::npos : end - pos);
            if (!line.empty() && line.back() == '\r')
                line.pop_back();

            const std::string trimmed = Trim(line);
            if (trimmed.rfind("; ---- ", 0) == 0)
            {
                blocks.push_back(MissingBlock());
                blocks.back().marker = trimmed;
                currentBlock = &blocks.back();
            }
            else
            {
                const std::string key = GetKeyFromLine(line);
                if (!key.empty() && !KeyExists(currentIni, key))
                {
                    if (currentBlock)
                        currentBlock->lines.push_back(line);
                    else
                        missingGlobals.push_back(line);
                }
            }

            if (end == std::string::npos)
                break;
            pos = end + 1;
        }

        std::string merged = currentIni;

        if (!missingGlobals.empty())
        {
            const std::string text = JoinLines(missingGlobals);
            size_t insertPos = merged.find("; ---- ");
            if (insertPos == std::string::npos)
                insertPos = merged.size();
            merged.insert(insertPos, text);
        }

        for (size_t i = 0; i < blocks.size(); ++i)
        {
            if (blocks[i].lines.empty())
                continue;

            const std::string missingText = JoinLines(blocks[i].lines);
            const size_t markerPos = merged.find(blocks[i].marker);

            if (markerPos != std::string::npos)
            {
                size_t insertPos = merged.find("; ---- ", markerPos + blocks[i].marker.size());
                if (insertPos == std::string::npos)
                    insertPos = merged.size();
                merged.insert(insertPos, missingText);
                continue;
            }

            size_t insertPos = std::string::npos;
            for (size_t next = i + 1; next < blocks.size(); ++next)
            {
                insertPos = merged.find(blocks[next].marker);
                if (insertPos != std::string::npos)
                    break;
            }

            std::string wholeBlock = "\r\n";
            wholeBlock += blocks[i].marker;
            wholeBlock += "\r\n";
            wholeBlock += missingText;

            if (insertPos == std::string::npos)
            {
                if (!merged.empty() && merged.back() != '\n')
                    merged += "\r\n";
                merged += wholeBlock;
            }
            else
            {
                merged.insert(insertPos, wholeBlock);
            }
        }

        return merged;
    }

    inline void EnsureIniExists()
    {
        static bool checkedThisProcess = false;
        if (checkedThisProcess)
            return;

        const std::string defaultIni = BuildDefaultIni();

        if (GetFileAttributesW(kIniPath) == INVALID_FILE_ATTRIBUTES)
        {
            if (WriteIni(defaultIni, CREATE_NEW))
                checkedThisProcess = true;
            return;
        }

        std::string currentIni;
        if (!ReadIni(currentIni))
            return;

        const std::string mergedIni = MergeMissingSettings(currentIni, defaultIni);
        if (mergedIni != currentIni && !WriteIni(mergedIni, CREATE_ALWAYS))
            return;

        checkedThisProcess = true;
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
