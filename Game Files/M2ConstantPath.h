#pragma once

#include <cstring>

// Indy 500, Over Rev (conversion drive-board modes) and Super GT 24h use
// constant-torque steering hardware. MAME exposes the raw Model 2 drive-board
// byte stream as wheel_motor, so non-motor command bytes must not be treated
// as separate spring/friction/sine effects or as an implicit force stop.
inline bool M2ConstantPathActive(const char* runningFFB, const char* rom)
{
	if (!runningFFB || !rom || std::strcmp(runningFFB, "m2new") != 0)
		return false;

	return
		std::strcmp(rom, "indy500") == 0 ||
		std::strcmp(rom, "indy500d") == 0 ||
		std::strcmp(rom, "indy500to") == 0 ||
		std::strcmp(rom, "overrev") == 0 ||
		std::strcmp(rom, "overrevb") == 0 ||
		std::strcmp(rom, "overrevba") == 0 ||
		std::strcmp(rom, "sgt24h") == 0;
}

inline double M2ConstantFilterOtherEffect(bool active, double strength)
{
	return active ? 0.0 : strength;
}

template <typename Sender>
inline void M2ConstantSend(Sender& sender, bool active, int raw, int direction, double strength)
{
	if (!active)
	{
		sender(direction, strength);
		return;
	}

	// Model 2 roll commands are the actual constant-torque motor commands.
	// 0x50-0x57 = force from right, 0x60-0x67 = force from left.
	// 0x00 is the explicit idle/off value. Everything else belongs to the
	// surrounding drive-board protocol and must not interrupt the held force.
	if ((raw >= 0x50 && raw <= 0x57) ||
		(raw >= 0x60 && raw <= 0x67) ||
		raw == 0x00)
	{
		sender(direction, strength);
	}
}

#define M2_CONSTANT_PATH_ACTIVE M2ConstantPathActive(RunningFFB, romname)

// M2 New already calculates the correct 8-step constant-force strength for
// 0x50-0x57 and 0x60-0x67. Gate those sends so protocol bytes such as 0x35,
// 0x40, 0xA0 and 0xB0 cannot cancel the currently held constant force.
#define sendConstant(direction, strength) \
	M2ConstantSend(sendConstant, M2_CONSTANT_PATH_ACTIVE, stateFFB, direction, strength)

// These games use the constant-torque path. Keep the existing M2 New decoder
// intact for the other Model 2 games, but suppress its synthetic effect types
// for the constant-torque games.
#define Spring(strength) \
	Spring(M2ConstantFilterOtherEffect(M2_CONSTANT_PATH_ACTIVE, strength))
#define Friction(strength) \
	Friction(M2ConstantFilterOtherEffect(M2_CONSTANT_PATH_ACTIVE, strength))
#define Sine(period, fadePeriod, strength) \
	Sine(period, fadePeriod, M2ConstantFilterOtherEffect(M2_CONSTANT_PATH_ACTIVE, strength))
#define Rumble(lowfrequency, highfrequency, length) \
	Rumble(M2ConstantFilterOtherEffect(M2_CONSTANT_PATH_ACTIVE, lowfrequency), \
		M2ConstantFilterOtherEffect(M2_CONSTANT_PATH_ACTIVE, highfrequency), length)
