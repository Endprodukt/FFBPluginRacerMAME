#pragma once

#include <Windows.h>
#include "SDL.h"
#include <cstdio>
#include <cstring>

// Keep the existing persistence mapping intact, but wrap its setup function so
// we can guarantee safe fallback keys and add keyboard input support without
// changing the established per-game logic.
#define CustomFFBStrengthSetup OriginalCustomFFBStrengthSetup
#include "PersistentValuesOriginal.h"
#undef CustomFFBStrengthSetup

extern int IncreaseFFBStrength;
extern int DecreaseFFBStrength;
extern int ResetFFBStrength;
extern int joystick_index1;

static LONG g_ffbStrengthKeyboardThreadStarted = 0;

static int FFBStrengthKeyNameToVirtualKey(const char* keyName)
{
	if (keyName == nullptr || keyName[0] == '\0')
		return 0;

	// Single character keys (A-Z, 0-9, punctuation).
	if (keyName[1] == '\0')
	{
		SHORT vk = VkKeyScanA(keyName[0]);
		if (vk != -1)
			return LOBYTE(vk);
	}

	int functionKey = 0;
	if ((keyName[0] == 'F' || keyName[0] == 'f') && sscanf_s(keyName + 1, "%d", &functionKey) == 1)
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
		{ "Keypad .", VK_DECIMAL }
	};

	for (const KeyNameMap& entry : keyMap)
	{
		if (lstrcmpiA(keyName, entry.name) == 0)
			return entry.vk;
	}

	return 0;
}

static void PushFFBStrengthButtonEvent(int button)
{
	if (button < 0 || button > 255)
		return;

	SDL_Event event;
	SDL_zero(event);
	event.type = SDL_JOYBUTTONDOWN;
	event.jbutton.type = SDL_JOYBUTTONDOWN;
	event.jbutton.which = joystick_index1;
	event.jbutton.button = static_cast<Uint8>(button);
	event.jbutton.state = SDL_PRESSED;
	SDL_PushEvent(&event);
}

static DWORD WINAPI FFBStrengthKeyboardThread(LPVOID)
{
	char increaseKeyName[64] = {};
	char decreaseKeyName[64] = {};
	char resetKeyName[64] = {};

	GetPrivateProfileStringA("Settings", "IncreaseFFBStrengthKey", "", increaseKeyName, sizeof(increaseKeyName), ".\\FFBPlugin.ini");
	GetPrivateProfileStringA("Settings", "DecreaseFFBStrengthKey", "", decreaseKeyName, sizeof(decreaseKeyName), ".\\FFBPlugin.ini");
	GetPrivateProfileStringA("Settings", "ResetFFBStrengthKey", "", resetKeyName, sizeof(resetKeyName), ".\\FFBPlugin.ini");

	const int increaseVk = FFBStrengthKeyNameToVirtualKey(increaseKeyName);
	const int decreaseVk = FFBStrengthKeyNameToVirtualKey(decreaseKeyName);
	const int resetVk = FFBStrengthKeyNameToVirtualKey(resetKeyName);

	if (increaseVk == 0 && decreaseVk == 0 && resetVk == 0)
		return 0;

	// 99 is the GUI's "Not Defined" value. If bindings are undefined or
	// duplicated, use reserved in-memory button IDs for the synthetic events.
	const int originalIncrease = IncreaseFFBStrength;
	const int originalDecrease = DecreaseFFBStrength;
	const int originalReset = ResetFFBStrength;

	if (increaseVk != 0 && (originalIncrease == 99 || originalIncrease < 0 || originalIncrease > 255 || originalIncrease == originalDecrease || originalIncrease == originalReset))
		IncreaseFFBStrength = 250;
	if (decreaseVk != 0 && (originalDecrease == 99 || originalDecrease < 0 || originalDecrease > 255 || originalDecrease == originalIncrease || originalDecrease == originalReset))
		DecreaseFFBStrength = 251;
	if (resetVk != 0 && (originalReset == 99 || originalReset < 0 || originalReset > 255 || originalReset == originalIncrease || originalReset == originalDecrease))
		ResetFFBStrength = 252;

	bool increaseWasDown = false;
	bool decreaseWasDown = false;
	bool resetWasDown = false;

	while (true)
	{
		const bool increaseDown = increaseVk != 0 && (GetAsyncKeyState(increaseVk) & 0x8000) != 0;
		const bool decreaseDown = decreaseVk != 0 && (GetAsyncKeyState(decreaseVk) & 0x8000) != 0;
		const bool resetDown = resetVk != 0 && (GetAsyncKeyState(resetVk) & 0x8000) != 0;

		if (increaseDown && !increaseWasDown)
			PushFFBStrengthButtonEvent(IncreaseFFBStrength);
		if (decreaseDown && !decreaseWasDown)
			PushFFBStrengthButtonEvent(DecreaseFFBStrength);
		if (resetDown && !resetWasDown)
			PushFFBStrengthButtonEvent(ResetFFBStrength);

		increaseWasDown = increaseDown;
		decreaseWasDown = decreaseDown;
		resetWasDown = resetDown;

		Sleep(15);
	}
}

static void StartFFBStrengthKeyboardThread()
{
	if (InterlockedCompareExchange(&g_ffbStrengthKeyboardThreadStarted, 1, 0) != 0)
		return;

	HANDLE thread = CreateThread(nullptr, 0, FFBStrengthKeyboardThread, nullptr, 0, nullptr);
	if (thread != nullptr)
		CloseHandle(thread);
	else
		InterlockedExchange(&g_ffbStrengthKeyboardThreadStarted, 0);
}

void CustomFFBStrengthSetup()
{
	// Always begin with valid generic keys. The old implementation leaves these
	// pointers null for an unmapped game, and WritePrivateProfileStringA treats a
	// null key name as a request to delete the complete INI section.
	CustomMaxForce = "MaxForce";
	CustomAlternativeMaxForceLeft = "AlternativeMaxForceLeft";
	CustomAlternativeMaxForceRight = "AlternativeMaxForceRight";

	OriginalCustomFFBStrengthSetup();

	// Speed Up uses per-game settings just like the other MAME racers.
	if (configGameId == 22 && romname != nullptr)
	{
		if (strcmp(romname, "speedup") == 0 || strcmp(romname, "speedup10") == 0 || strcmp(romname, "speedup12") == 0 ||
			strcmp(romname, "speedup20") == 0 || strcmp(romname, "speedup20a") == 0 || strcmp(romname, "speedup21") == 0)
		{
			if (AlternativeFFB == 1)
			{
				CustomAlternativeMaxForceLeft = "AlternativeMaxForceLeftSpeedUp";
				CustomAlternativeMaxForceRight = "AlternativeMaxForceRightSpeedUp";
			}
			else
			{
				CustomMaxForce = "MaxForceSpeedUp";
			}
		}
	}

	StartFFBStrengthKeyboardThread();
}
