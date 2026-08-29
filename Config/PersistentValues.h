#pragma once

#include <Windows.h>
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <string>

// Keep the established per-game persistence mappings intact.
#define CustomFFBStrengthSetup OriginalCustomFFBStrengthSetup
#include "PersistentValuesOriginal.h"
#undef CustomFFBStrengthSetup

extern int StepFFBStrength;
extern int EnableFFBStrengthDynamicAdjustment;

static LONG g_ffbStrengthKeyboardThreadStarted = 0;
static HHOOK g_ffbStrengthKeyboardHook = nullptr;
static char g_ffbPluginIniPath[MAX_PATH] = {};
static char g_ffbKeyboardDebugLogPath[MAX_PATH] = {};
static char g_increaseFFBStrengthKeyName[64] = {};
static char g_decreaseFFBStrengthKeyName[64] = {};
static char g_resetFFBStrengthKeyName[64] = {};
static int g_increaseFFBStrengthVk = 0;
static int g_decreaseFFBStrengthVk = 0;
static int g_resetFFBStrengthVk = 0;
static bool g_increaseFFBStrengthKeyDown = false;
static bool g_decreaseFFBStrengthKeyDown = false;
static bool g_resetFFBStrengthKeyDown = false;

static void StartFFBStrengthKeyboardThread();
void CustomFFBStrengthSetup();

static void FFBKeyboardDebugLog(const char* format, ...)
{
	if (g_ffbKeyboardDebugLogPath[0] == '\0')
		return;

	FILE* file = nullptr;
	if (fopen_s(&file, g_ffbKeyboardDebugLogPath, "a") != 0 || file == nullptr)
		return;

	SYSTEMTIME time;
	GetLocalTime(&time);
	fprintf(file, "%02u:%02u:%02u.%03u ",
		time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);

	va_list args;
	va_start(args, format);
	vfprintf(file, format, args);
	va_end(args);

	fputc('\n', file);
	fclose(file);
}

static void FFBKeyboardSetupDebugLogPath()
{
	if (g_ffbPluginIniPath[0] == '\0')
	{
		strcpy_s(g_ffbKeyboardDebugLogPath, ".\\FFBKeyboardDebug.log");
		return;
	}

	strcpy_s(g_ffbKeyboardDebugLogPath, g_ffbPluginIniPath);
	char* slash = strrchr(g_ffbKeyboardDebugLogPath, '\\');
	char* forwardSlash = strrchr(g_ffbKeyboardDebugLogPath, '/');
	if (forwardSlash != nullptr && (slash == nullptr || forwardSlash > slash))
		slash = forwardSlash;

	if (slash != nullptr)
	{
		const size_t used = static_cast<size_t>((slash + 1) - g_ffbKeyboardDebugLogPath);
		strcpy_s(slash + 1, MAX_PATH - used, "FFBKeyboardDebug.log");
	}
	else
	{
		strcpy_s(g_ffbKeyboardDebugLogPath, ".\\FFBKeyboardDebug.log");
	}
}

static int FFBStrengthKeyNameToVirtualKey(const char* keyName)
{
	if (keyName == nullptr || keyName[0] == '\0')
		return 0;

	if (keyName[1] == '\0')
	{
		SHORT vk = VkKeyScanA(keyName[0]);
		if (vk != -1)
			return LOBYTE(vk);
	}

	int functionKey = 0;
	if ((keyName[0] == 'F' || keyName[0] == 'f') &&
		sscanf_s(keyName + 1, "%d", &functionKey) == 1)
	{
		if (functionKey >= 1 && functionKey <= 24)
			return VK_F1 + functionKey - 1;
	}

	struct KeyNameMap
	{
		const char* name;
		int vk;
	};

	static const KeyNameMap keyMap[] =
	{
		{ "Return", VK_RETURN },
		{ "Enter", VK_RETURN },
		{ "Escape", VK_ESCAPE },
		{ "Esc", VK_ESCAPE },
		{ "Space", VK_SPACE },
		{ "Tab", VK_TAB },
		{ "Backspace", VK_BACK },
		{ "Delete", VK_DELETE },
		{ "Insert", VK_INSERT },
		{ "Home", VK_HOME },
		{ "End", VK_END },
		{ "PageUp", VK_PRIOR },
		{ "Page Up", VK_PRIOR },
		{ "PageDown", VK_NEXT },
		{ "Page Down", VK_NEXT },
		{ "Up", VK_UP },
		{ "Down", VK_DOWN },
		{ "Left", VK_LEFT },
		{ "Right", VK_RIGHT },
		{ "Left Shift", VK_LSHIFT },
		{ "Right Shift", VK_RSHIFT },
		{ "Left Ctrl", VK_LCONTROL },
		{ "Right Ctrl", VK_RCONTROL },
		{ "Left Alt", VK_LMENU },
		{ "Right Alt", VK_RMENU },
		{ "Left GUI", VK_LWIN },
		{ "Right GUI", VK_RWIN },
		{ "CapsLock", VK_CAPITAL },
		{ "NumLock", VK_NUMLOCK },
		{ "ScrollLock", VK_SCROLL },
		{ "Pause", VK_PAUSE },
		{ "PrintScreen", VK_SNAPSHOT },
		{ "Keypad 0", VK_NUMPAD0 },
		{ "Keypad 1", VK_NUMPAD1 },
		{ "Keypad 2", VK_NUMPAD2 },
		{ "Keypad 3", VK_NUMPAD3 },
		{ "Keypad 4", VK_NUMPAD4 },
		{ "Keypad 5", VK_NUMPAD5 },
		{ "Keypad 6", VK_NUMPAD6 },
		{ "Keypad 7", VK_NUMPAD7 },
		{ "Keypad 8", VK_NUMPAD8 },
		{ "Keypad 9", VK_NUMPAD9 },
		{ "Keypad +", VK_ADD },
		{ "Keypad -", VK_SUBTRACT },
		{ "Keypad *", VK_MULTIPLY },
		{ "Keypad /", VK_DIVIDE },
		{ "Keypad .", VK_DECIMAL },
		{ "Keypad Enter", VK_RETURN }
	};

	for (const KeyNameMap& entry : keyMap)
	{
		if (lstrcmpiA(keyName, entry.name) == 0)
			return entry.vk;
	}

	return 0;
}

struct FFBStrengthKeyboardConfigInitializer
{
	FFBStrengthKeyboardConfigInitializer()
	{
		DWORD pathLength = GetFullPathNameA(
			".\\FFBPlugin.ini",
			MAX_PATH,
			g_ffbPluginIniPath,
			nullptr);

		if (pathLength == 0 || pathLength >= MAX_PATH)
			strcpy_s(g_ffbPluginIniPath, ".\\FFBPlugin.ini");

		FFBKeyboardSetupDebugLogPath();
		DeleteFileA(g_ffbKeyboardDebugLogPath);

		GetPrivateProfileStringA(
			"Settings", "IncreaseFFBStrengthKey", "",
			g_increaseFFBStrengthKeyName,
			sizeof(g_increaseFFBStrengthKeyName),
			g_ffbPluginIniPath);

		GetPrivateProfileStringA(
			"Settings", "DecreaseFFBStrengthKey", "",
			g_decreaseFFBStrengthKeyName,
			sizeof(g_decreaseFFBStrengthKeyName),
			g_ffbPluginIniPath);

		GetPrivateProfileStringA(
			"Settings", "ResetFFBStrengthKey", "",
			g_resetFFBStrengthKeyName,
			sizeof(g_resetFFBStrengthKeyName),
			g_ffbPluginIniPath);

		g_increaseFFBStrengthVk =
			FFBStrengthKeyNameToVirtualKey(g_increaseFFBStrengthKeyName);
		g_decreaseFFBStrengthVk =
			FFBStrengthKeyNameToVirtualKey(g_decreaseFFBStrengthKeyName);
		g_resetFFBStrengthVk =
			FFBStrengthKeyNameToVirtualKey(g_resetFFBStrengthKeyName);

		FFBKeyboardDebugLog("INIT ini=%s", g_ffbPluginIniPath);
		FFBKeyboardDebugLog(
			"BINDINGS increase='%s' vk=%d decrease='%s' vk=%d reset='%s' vk=%d",
			g_increaseFFBStrengthKeyName, g_increaseFFBStrengthVk,
			g_decreaseFFBStrengthKeyName, g_decreaseFFBStrengthVk,
			g_resetFFBStrengthKeyName, g_resetFFBStrengthVk);

		FFBKeyboardDebugLog("INIT starting keyboard thread independently");
		StartFFBStrengthKeyboardThread();
	}
};

static FFBStrengthKeyboardConfigInitializer g_ffbStrengthKeyboardConfigInitializer;

static BOOL FFBPluginSafeWritePrivateProfileStringA(
	LPCSTR appName,
	LPCSTR keyName,
	LPCSTR value,
	LPCSTR fileName)
{
	if (appName == nullptr || keyName == nullptr || fileName == nullptr)
		return FALSE;

	LPCSTR resolvedFileName = fileName;
	if (g_ffbPluginIniPath[0] != '\0' &&
		(lstrcmpiA(fileName, ".\\FFBPlugin.ini") == 0 ||
		 lstrcmpiA(fileName, "FFBPlugin.ini") == 0))
	{
		resolvedFileName = g_ffbPluginIniPath;
	}

	return ::WritePrivateProfileStringA(
		appName, keyName, value, resolvedFileName);
}

#define WritePrivateProfileStringA FFBPluginSafeWritePrivateProfileStringA

static void PersistKeyboardFFBStrength()
{
	if (!EnableFFBStrengthPersistence)
	{
		FFBKeyboardDebugLog("PERSIST disabled");
		return;
	}

	if (AlternativeFFB)
	{
		if (CustomAlternativeMaxForceLeft == nullptr ||
			CustomAlternativeMaxForceRight == nullptr)
		{
			FFBKeyboardDebugLog("PERSIST skipped: alternative key is NULL");
			return;
		}

		const std::string leftValue =
			std::to_string(configAlternativeMaxForceLeft);
		const std::string rightValue =
			std::to_string(configAlternativeMaxForceRight);

		FFBKeyboardDebugLog(
			"PERSIST %s=%s %s=%s",
			CustomAlternativeMaxForceLeft, leftValue.c_str(),
			CustomAlternativeMaxForceRight, rightValue.c_str());

		FFBPluginSafeWritePrivateProfileStringA(
			"Settings",
			CustomAlternativeMaxForceLeft,
			leftValue.c_str(),
			g_ffbPluginIniPath);

		FFBPluginSafeWritePrivateProfileStringA(
			"Settings",
			CustomAlternativeMaxForceRight,
			rightValue.c_str(),
			g_ffbPluginIniPath);
	}
	else
	{
		if (CustomMaxForce == nullptr)
		{
			FFBKeyboardDebugLog("PERSIST skipped: max-force key is NULL");
			return;
		}

		const std::string value = std::to_string(configMaxForce);
		FFBKeyboardDebugLog("PERSIST %s=%s", CustomMaxForce, value.c_str());

		FFBPluginSafeWritePrivateProfileStringA(
			"Settings",
			CustomMaxForce,
			value.c_str(),
			g_ffbPluginIniPath);
	}
}

enum FFBStrengthKeyboardAction
{
	FFB_STRENGTH_INCREASE,
	FFB_STRENGTH_DECREASE,
	FFB_STRENGTH_RESET
};

static void ApplyKeyboardFFBStrength(FFBStrengthKeyboardAction action)
{
	CustomFFBStrengthSetup();

	const int beforeMaxForce = configMaxForce;
	const int beforeAlternativeLeft = configAlternativeMaxForceLeft;
	const int beforeAlternativeRight = configAlternativeMaxForceRight;

	if (action == FFB_STRENGTH_RESET)
	{
		DefaultConfigValues();
		FFBKeyboardDebugLog(
			"ACTION reset max=%d->%d altL=%d->%d altR=%d->%d",
			beforeMaxForce, configMaxForce,
			beforeAlternativeLeft, configAlternativeMaxForceLeft,
			beforeAlternativeRight, configAlternativeMaxForceRight);
		PersistKeyboardFFBStrength();
		return;
	}

	if (AlternativeFFB)
	{
		if (action == FFB_STRENGTH_INCREASE)
		{
			if (configAlternativeMaxForceRight >= 0 &&
				configAlternativeMaxForceRight < 100)
			{
				configAlternativeMaxForceRight += StepFFBStrength;
				if (configAlternativeMaxForceRight > 100)
					configAlternativeMaxForceRight = 100;
			}

			if (configAlternativeMaxForceLeft <= 0 &&
				configAlternativeMaxForceLeft > -100)
			{
				configAlternativeMaxForceLeft -= StepFFBStrength;
				if (configAlternativeMaxForceLeft < -100)
					configAlternativeMaxForceLeft = -100;
			}
		}
		else
		{
			if (configAlternativeMaxForceRight > 0 &&
				configAlternativeMaxForceRight <= 100)
			{
				configAlternativeMaxForceRight -= StepFFBStrength;
				if (configAlternativeMaxForceRight < 0)
					configAlternativeMaxForceRight = 0;
			}

			if (configAlternativeMaxForceLeft < 0 &&
				configAlternativeMaxForceLeft >= -100)
			{
				configAlternativeMaxForceLeft += StepFFBStrength;
				if (configAlternativeMaxForceLeft > 0)
					configAlternativeMaxForceLeft = 0;
			}
		}
	}
	else
	{
		if (action == FFB_STRENGTH_INCREASE)
		{
			if (configMaxForce >= 0 && configMaxForce < 100)
			{
				configMaxForce += StepFFBStrength;
				if (configMaxForce > 100)
					configMaxForce = 100;
			}
		}
		else
		{
			if (configMaxForce > 0 && configMaxForce <= 100)
			{
				configMaxForce -= StepFFBStrength;
				if (configMaxForce < 0)
					configMaxForce = 0;
			}
		}
	}

	FFBKeyboardDebugLog(
		"ACTION %s max=%d->%d altL=%d->%d altR=%d->%d",
		action == FFB_STRENGTH_INCREASE ? "increase" : "decrease",
		beforeMaxForce, configMaxForce,
		beforeAlternativeLeft, configAlternativeMaxForceLeft,
		beforeAlternativeRight, configAlternativeMaxForceRight);

	PersistKeyboardFFBStrength();
}

static LRESULT CALLBACK FFBStrengthKeyboardHookProc(
	int nCode,
	WPARAM wParam,
	LPARAM lParam)
{
	if (nCode == HC_ACTION && lParam != 0)
	{
		const KBDLLHOOKSTRUCT* keyboard =
			reinterpret_cast<const KBDLLHOOKSTRUCT*>(lParam);

		const bool keyDown =
			wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN;
		const bool keyUp =
			wParam == WM_KEYUP || wParam == WM_SYSKEYUP;
		const DWORD vk = keyboard->vkCode;

		if (keyDown)
		{
			FFBKeyboardDebugLog(
				"KEYDOWN vk=%lu scan=%lu flags=0x%08lx",
				static_cast<unsigned long>(keyboard->vkCode),
				static_cast<unsigned long>(keyboard->scanCode),
				static_cast<unsigned long>(keyboard->flags));
		}

		if (g_increaseFFBStrengthVk != 0 &&
			vk == static_cast<DWORD>(g_increaseFFBStrengthVk))
		{
			if (keyDown && !g_increaseFFBStrengthKeyDown)
			{
				g_increaseFFBStrengthKeyDown = true;
				FFBKeyboardDebugLog("MATCH increase");
				ApplyKeyboardFFBStrength(FFB_STRENGTH_INCREASE);
			}
			else if (keyUp)
			{
				g_increaseFFBStrengthKeyDown = false;
			}
		}

		if (g_decreaseFFBStrengthVk != 0 &&
			vk == static_cast<DWORD>(g_decreaseFFBStrengthVk))
		{
			if (keyDown && !g_decreaseFFBStrengthKeyDown)
			{
				g_decreaseFFBStrengthKeyDown = true;
				FFBKeyboardDebugLog("MATCH decrease");
				ApplyKeyboardFFBStrength(FFB_STRENGTH_DECREASE);
			}
			else if (keyUp)
			{
				g_decreaseFFBStrengthKeyDown = false;
			}
		}

		if (g_resetFFBStrengthVk != 0 &&
			vk == static_cast<DWORD>(g_resetFFBStrengthVk))
		{
			if (keyDown && !g_resetFFBStrengthKeyDown)
			{
				g_resetFFBStrengthKeyDown = true;
				FFBKeyboardDebugLog("MATCH reset");
				ApplyKeyboardFFBStrength(FFB_STRENGTH_RESET);
			}
			else if (keyUp)
			{
				g_resetFFBStrengthKeyDown = false;
			}
		}
	}

	return CallNextHookEx(g_ffbStrengthKeyboardHook, nCode, wParam, lParam);
}

static bool FFBStrengthPollKey(int virtualKey, bool& wasDown)
{
	if (virtualKey == 0)
	{
		wasDown = false;
		return false;
	}

	const bool isDown = (GetAsyncKeyState(virtualKey) & 0x8000) != 0;
	if (isDown && !wasDown)
	{
		wasDown = true;
		return true;
	}

	if (!isDown)
		wasDown = false;

	return false;
}

static DWORD WINAPI FFBStrengthKeyboardThread(LPVOID)
{
	FFBKeyboardDebugLog(
		"THREAD polling start vk increase=%d decrease=%d reset=%d",
		g_increaseFFBStrengthVk,
		g_decreaseFFBStrengthVk,
		g_resetFFBStrengthVk);

	if (g_increaseFFBStrengthVk == 0 &&
		g_decreaseFFBStrengthVk == 0 &&
		g_resetFFBStrengthVk == 0)
	{
		FFBKeyboardDebugLog("THREAD abort: no valid bindings");
		InterlockedExchange(&g_ffbStrengthKeyboardThreadStarted, 0);
		return 0;
	}

	FFBKeyboardDebugLog("THREAD polling active");

	while (true)
	{
		if (EnableFFBStrengthDynamicAdjustment)
		{
			if (FFBStrengthPollKey(
				g_increaseFFBStrengthVk,
				g_increaseFFBStrengthKeyDown))
			{
				FFBKeyboardDebugLog("POLL match increase");
				ApplyKeyboardFFBStrength(FFB_STRENGTH_INCREASE);
			}

			if (FFBStrengthPollKey(
				g_decreaseFFBStrengthVk,
				g_decreaseFFBStrengthKeyDown))
			{
				FFBKeyboardDebugLog("POLL match decrease");
				ApplyKeyboardFFBStrength(FFB_STRENGTH_DECREASE);
			}

			if (FFBStrengthPollKey(
				g_resetFFBStrengthVk,
				g_resetFFBStrengthKeyDown))
			{
				FFBKeyboardDebugLog("POLL match reset");
				ApplyKeyboardFFBStrength(FFB_STRENGTH_RESET);
			}
		}
		else
		{
			g_increaseFFBStrengthKeyDown = false;
			g_decreaseFFBStrengthKeyDown = false;
			g_resetFFBStrengthKeyDown = false;
		}

		Sleep(16);
	}
}

static void StartFFBStrengthKeyboardThread()
{
	if (InterlockedCompareExchange(
		&g_ffbStrengthKeyboardThreadStarted, 1, 0) != 0)
	{
		FFBKeyboardDebugLog("START ignored: thread already started");
		return;
	}

	FFBKeyboardDebugLog("START creating keyboard thread");
	HANDLE thread = CreateThread(
		nullptr, 0, FFBStrengthKeyboardThread, nullptr, 0, nullptr);

	if (thread != nullptr)
	{
		FFBKeyboardDebugLog("START thread created handle=%p", thread);
		CloseHandle(thread);
	}
	else
	{
		FFBKeyboardDebugLog(
			"START CreateThread FAILED error=%lu",
			static_cast<unsigned long>(GetLastError()));
		InterlockedExchange(&g_ffbStrengthKeyboardThreadStarted, 0);
	}
}

void CustomFFBStrengthSetup()
{
	CustomMaxForce = "MaxForce";
	CustomAlternativeMaxForceLeft = "AlternativeMaxForceLeft";
	CustomAlternativeMaxForceRight = "AlternativeMaxForceRight";

	OriginalCustomFFBStrengthSetup();

	if (configGameId == 22 && romname != nullptr)
	{
		if (strcmp(romname, "speedup") == 0 ||
			strcmp(romname, "speedup10") == 0 ||
			strcmp(romname, "speedup12") == 0 ||
			strcmp(romname, "speedup20") == 0 ||
			strcmp(romname, "speedup20a") == 0 ||
			strcmp(romname, "speedup21") == 0)
		{
			if (AlternativeFFB == 1)
			{
				CustomAlternativeMaxForceLeft =
					"AlternativeMaxForceLeftSpeedUp";
				CustomAlternativeMaxForceRight =
					"AlternativeMaxForceRightSpeedUp";
			}
			else
			{
				CustomMaxForce = "MaxForceSpeedUp";
			}
		}
	}

	FFBKeyboardDebugLog(
		"SETUP gameId=%d rom=%s alt=%d key=%s altLeft=%s altRight=%s",
		configGameId,
		romname != nullptr ? romname : "<null>",
		AlternativeFFB,
		CustomMaxForce != nullptr ? CustomMaxForce : "<null>",
		CustomAlternativeMaxForceLeft != nullptr ? CustomAlternativeMaxForceLeft : "<null>",
		CustomAlternativeMaxForceRight != nullptr ? CustomAlternativeMaxForceRight : "<null>");

	StartFFBStrengthKeyboardThread();
}
