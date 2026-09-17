// cl: /O2 /DNDEBUG /MD

// FESL dotted-quad parse at 0x00655790 (92B). Direct reuse of
// Open-BFME-1 Code/GameEngine/Source/GameNetwork/Y2FeslAddressFormat.cpp
// (Rva007E8760Addr::parse at 0x7E86D0, 92B — size-diff zero). Parse packs
// %d.%d.%d.%d into this+8 (network order via shift-add) and stores the
// second argument at +0xC. Retail calls the sscanf import THUNK directly
// (E8 to 0x629892, not FF15 to the IAT), so the TU keeps BFME1's
// plain-extern sscanf decl (C `sscanf` decorates to `_sscanf`, resolving
// through the existing pin); stdio.h's dllimport spelling emits the
// indirect call and misses by one byte.

extern "C" int __cdecl sscanf(const char *buf, const char *fmt, ...);

class Rva007E8760Addr
{
public:
    void parse(const char *addressText, int extra);

private:
    char m_pad[8];
    unsigned m_addr;
    int m_extra;
};

void Rva007E8760Addr::parse(const char *addressText, int extra)
{
    int firstOctet, secondOctet, thirdOctet, fourthOctet;
    sscanf(addressText, "%d.%d.%d.%d", &firstOctet, &secondOctet, &thirdOctet, &fourthOctet);
    unsigned packedAddress = (unsigned)firstOctet;
    packedAddress = (packedAddress << 8) + (unsigned)secondOctet;
    packedAddress = (packedAddress << 8) + (unsigned)thirdOctet;
    packedAddress = (packedAddress << 8) + (unsigned)fourthOctet;
    m_addr = packedAddress;
    m_extra = extra;
}
