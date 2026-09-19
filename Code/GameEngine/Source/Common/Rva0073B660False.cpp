// Retail 0x0073B660: three-byte __cdecl predicate stub with one shape:
//
//     xor al,al / ret
//
// WHAT THE BYTES SHOW. No use of any register or stack slot and no stack
// cleanup: a free __cdecl function whose whole body returns byte-zero. All
// eleven direct call sites push two dwords, add esp,8 afterwards, and test
// al (bool use), so the callee takes two stack arguments it ignores. The
// 8-bit xor (not full-eax) is the compiler's byte/bool return, matching the
// test-al callers.
//
// WHAT IS NOT SHOWN. The argument types are not witnessed anywhere -- the
// body never touches them -- so they are carried as (void *, int) from the
// call shapes (pointer-ish first push, small-int second push). The stride-28
// .rdata descriptor tables that also store this address place it beside the
// Subsystem family's shared 0xA9E440 slot (see SubsystemNameGetters.cpp),
// but no vftable or call site witnesses the enclosing class, so the row is
// named for its own address with the proven behavior in the name.

bool Rva0073B660False(void *, int)
{
	return false;
}
