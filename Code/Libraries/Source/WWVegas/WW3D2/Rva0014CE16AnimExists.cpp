// cl: /O1 /MD /DNDEBUG /DWIN32 /D_WINDOWS
//
// ?Rva0014CE16_AnimExists@@YA_NPBD@Z @ 0x0014CE16 (81 bytes).
// Animation-asset existence check: builds the "a*"+name key lowercased in
// a 512-byte buffer and returns the registry contains-check. No SEH (no
// object lifetimes); the checker address is pinned.

extern "C" char *strcpy(char *destination, const char *source);
#pragma function(strcpy)
extern "C" __declspec(dllimport) char *__cdecl _strlwr(char *string);

// Registry contains-check (retail 0x0061F0D0, 28B): null name or null
// registry answers false, else tail-calls the registry lookup 0xA21170.
extern bool __cdecl Rva0061F0D0_Contains(const char *name);

// ?Rva0014CE16_AnimExists@@YA_NPBD@Z
bool Rva0014CE16_AnimExists(const char *name)
{
	if (name == 0)
		return false;

	char lookup[512];
	strcpy(lookup, "a*");
	strcpy(lookup + 2, name);
	_strlwr(lookup);
	return Rva0061F0D0_Contains(lookup);
}
