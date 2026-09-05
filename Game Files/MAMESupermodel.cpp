#include "MAMESupermodel.h"
#include <cstring>

// Keep the existing MAME/Supermodel implementation intact and wrap the
// MAME output callback so Super Monaco GP can combine its three shaker bits.
int __stdcall mame_updatestate(const char* id, int state);

// Function-like macros rename the original definitions/calls in the included
// core. A bare callback assignment (mame_updatestate_ptr = mame_updatestate)
// intentionally still resolves to the wrapper declared above.
#define mame_updatestate(...) mame_updatestate_base(__VA_ARGS__)
#define FFBLoop(...) FFBLoopBase(__VA_ARGS__)
#include "MAMESupermodel_base.inc"
#undef FFBLoop
#undef mame_updatestate

namespace
{
	volatile LONG g_smgp_lamp0 = 0;
	volatile LONG g_smgp_lamp1 = 0;
	volatile LONG g_smgp_lamp2 = 0;
	int g_smgp_last_level = -1;

	const char* const g_smgp_roms[] =
	{
		// Official Sega sets
		"smgp", "smgp6", "smgp5",
		"smgpu", "smgpu1", "smgpu2",
		"smgpj", "smgpja",

		// Decrypted/bootleg sets currently present in MAME
		"smgpd", "smgp6d", "smgp5d",
		"smgpud", "smgpu1d", "smgpu2d",
		"smgpjd"
	};

	bool IsSuperMonacoGPRom(const char* romName)
	{
		if (!romName || !*romName)
			return false;

		for (const char* smgpRom : g_smgp_roms)
		{
			if (std::strcmp(romName, smgpRom) == 0)
				return true;
		}

		return false;
	}

	bool IsOutputName(const char* name, const char* fullName, const char* shortName)
	{
		return name &&
			(std::strcmp(name, fullName) == 0 || std::strcmp(name, shortName) == 0);
	}

	LONG ReadSmgpBit(volatile LONG* value)
	{
		return InterlockedCompareExchange(value, 0, 0);
	}

	int GetSuperMonacoGPRumbleLevel()
	{
		// The upright shaker uses a 3-bit speed value:
		// lamp2 = bit 0 (1), lamp0 = bit 1 (2), lamp1 = bit 2 (4).
		return (ReadSmgpBit(&g_smgp_lamp2) ? 1 : 0)
			| (ReadSmgpBit(&g_smgp_lamp0) ? 2 : 0)
			| (ReadSmgpBit(&g_smgp_lamp1) ? 4 : 0);
	}

	void ApplySuperMonacoGPWheelRumble()
	{
		if (!mytriggers)
			return;

		const int level = GetSuperMonacoGPRumbleLevel();

		// Original upright hardware has seven shaker-motor speed steps.
		// On a modern FFB wheel we approximate that with a periodic effect:
		// higher steps increase both vibration frequency and strength.
		static const UINT16 periodByLevel[8] =
		{
			0, 80, 68, 58, 49, 42, 36, 31
		};

		if (level == 0)
		{
			mytriggers->Sine(0, 0, 0.0);
		}
		else
		{
			const double strength = level / 7.0;
			mytriggers->Sine(periodByLevel[level], 0, strength);
		}

		if (level != g_smgp_last_level)
		{
			if (myhelpers && enableLogging)
				myhelpers->info("Super Monaco GP wheel rumble level %d", level);

			g_smgp_last_level = level;
		}
	}
}

int __stdcall mame_updatestate(const char* id, int state)
{
	LPCSTR outputName = get_name_from_id((int)id);

	if (IsSuperMonacoGPRom(GameName))
	{
		bool rumbleBitChanged = false;

		if (IsOutputName(outputName, "mainpcb:lamp0", "lamp0"))
		{
			InterlockedExchange(&g_smgp_lamp0, state ? 1 : 0);
			rumbleBitChanged = true;
		}
		else if (IsOutputName(outputName, "mainpcb:lamp1", "lamp1"))
		{
			InterlockedExchange(&g_smgp_lamp1, state ? 1 : 0);
			rumbleBitChanged = true;
		}
		else if (IsOutputName(outputName, "mainpcb:lamp2", "lamp2"))
		{
			InterlockedExchange(&g_smgp_lamp2, state ? 1 : 0);
			rumbleBitChanged = true;
		}

		if (rumbleBitChanged)
			ApplySuperMonacoGPWheelRumble();
	}

	return mame_updatestate_base(id, state);
}

void MAMESupermodel::FFBLoop(EffectConstants* constants, Helpers* helpers, EffectTriggers* triggers)
{
	FFBLoopBase(constants, helpers, triggers);

	// Mark every explicit Super Monaco GP set as supported. Do not rely on the
	// MAME parent relationship or a broad "smgp*" prefix match.
	if (IsSuperMonacoGPRom(GameName))
	{
		RomGameName = true;
		RunningFFB = "SuperMonacoGPActive";
	}
}
