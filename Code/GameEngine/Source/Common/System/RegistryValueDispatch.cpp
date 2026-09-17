// cl: /DNDEBUG /MD

// Registry-value dispatcher at 0x0002F720 (288B). No BFME1 twin: the key
// set (SkuName, GameName, GameRegPath, InstallerRegPath, OnlineServer,
// UserDataLeafName, G1..G4) is BFME2-new. The sole caller walks a
// double-null-terminated registry block, splits each entry at '=', and calls
// here with (key, value); the matching global keeps the value pointer.
//
// The comparator address is loaded once from the _strcmpi IAT slot into EDI
// and reused for all ten calls, so the source caches it in a local: taking
// the address of the dllimport emits exactly that load. Each match stores
// the value and returns; no match falls through.

extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *a, const char *b);

const char *g_SkuNameValue;
const char *g_GameNameValue;
const char *g_GameRegPathValue;
const char *g_InstallerRegPathValue;
const char *g_OnlineServerValue;
const char *g_UserDataLeafNameValue;
const char *g_G1Value;
const char *g_G2Value;
const char *g_G3Value;
const char *g_G4Value;

void __cdecl Rva0002F720(const char *key, const char *value)
{
    const char *k = key;
    int (__cdecl *compare)(const char *, const char *) = _strcmpi;
    if (compare(k, "SkuName") == 0)
    {
        g_SkuNameValue = value;
        return;
    }
    if (compare(k, "GameName") == 0)
    {
        g_GameNameValue = value;
        return;
    }
    if (compare(k, "GameRegPath") == 0)
    {
        g_GameRegPathValue = value;
        return;
    }
    if (compare(k, "InstallerRegPath") == 0)
    {
        g_InstallerRegPathValue = value;
        return;
    }
    if (compare(k, "OnlineServer") == 0)
    {
        g_OnlineServerValue = value;
        return;
    }
    if (compare(k, "UserDataLeafName") == 0)
    {
        g_UserDataLeafNameValue = value;
        return;
    }
    if (compare(k, "G1") == 0)
    {
        g_G1Value = value;
        return;
    }
    if (compare(k, "G2") == 0)
    {
        g_G2Value = value;
        return;
    }
    if (compare(k, "G3") == 0)
    {
        g_G3Value = value;
        return;
    }
    if (compare(k, "G4") == 0)
    {
        g_G4Value = value;
        return;
    }
}
