// ?parseDurationReal@INI@@SAXPAV1@PAX1PBX@Z
// partial score=0.89 date=2026-09-14
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
//
// INI::parseDurationReal, retail 0x00338B0A (38 bytes).
// Ported from the BFME1 reconstruction (Code/GameEngine/Source/Common/INI/INI_stl.cpp),
// with one BFME2 repair proven by retail: scanReal is a thiscall on INI
// (pin ?scanReal@INI@@QAEMPBD@Z at 0x2EDA5, mov ecx ini), where BFME1 spells
// it static (?scanReal@INI@@SAMPBD@Z). getNextToken pin pre-existed at
// 0x2DF97 (thiscall, NULL separator). Convert inlines to val * 0.005f
// (float at 0xDBA4EC, 5 logic frames per second).

typedef float Real;

class INI
{
public:
	const char *getNextToken(const char *separator);
	Real scanReal(const char *token);
	static void parseDurationReal(INI *ini, void *instance, void *store, const void *userData);
};

inline Real ConvertDurationFromMsecsToFrames(Real val)
{
	return 0.005f * val;
}

// ?parseDurationReal@INI@@SAXPAV1@PAX1PBX@Z
// Retail reloads ini from the stack for both calls (no esi save); volatile
// forces the reloads with identical behavior.
void INI::parseDurationReal(INI *volatile ini, void *instance, void *store, const void *userData)
{
	Real val = ini->scanReal(ini->getNextToken(0));
	*(Real *)store = ConvertDurationFromMsecsToFrames(val);
}
