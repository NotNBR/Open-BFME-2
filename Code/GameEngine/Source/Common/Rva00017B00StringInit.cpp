// 0x00017B00 (33B): in-place wide-string initializer over a static empty.
//
// WHAT THE BYTES SHOW. The body spills a volatile slot and `other`
// (push ecx / push esi), loads `other` to esi, pushes the .data static at
// 0x009DEEF0 (32 zero bytes; DIR32 slot the patcher fills), points ecx at
// `other`, and calls 0x0000EA90 — the ledger's matched STLport 4.5.3
// wide-string copy constructor — then returns `other` (ret 4: thiscall with
// one stack param). So this copy-constructs a wide string at `other` from
// the static empty and hands `other` back. The volatile store lands at
// [esp+8] because the compiler sinks it past the argument push, which is
// also what makes the slot read back as the callee's-temporary area.
//
// WHY NOT THE SERVED NAME. bfme1_sweep's near queue serves this address as
// ?bfmeGoDNC / ?bfmeGoDNG (BfmeConv735/739 two-param donors, ret 8 against
// retail ret 4); the unserved one-param twin ?bfmeGoDND (BfmeConv736) has
// the right arity but all three donors call a BfmeOtherDN method while
// retail's call enters the string copy ctor (capstone: call 0xEA90, the
// matched row, not mid-body). The DN identities are therefore refuted for
// game.dat and the address keeps an opaque address-derived name. One data
// pin (the static); the callee is already rowed so no code pin.

// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /D_STLP_USE_STATIC_LIB /EHs-c-
// stlport
typedef unsigned short BfmeWChar;

namespace _STL
{
template <class T> class char_traits {};
template <class T> class allocator {};
template <class C, class T, class A> class basic_string
{
public:
	basic_string(const basic_string &src);
};
typedef basic_string<BfmeWChar, char_traits<BfmeWChar>, allocator<BfmeWChar> > BfmeWideString;
}

#include <new>

extern unsigned char g_009DEEF0Static[];

class Rva00017B00StringInit
{
public:
	void *init(void *other);
};

void *Rva00017B00StringInit::init(void *other)
{
	volatile int tmp = 0;
	_STL::BfmeWideString *slot = static_cast<_STL::BfmeWideString *>(other);
	const _STL::BfmeWideString &empty = *reinterpret_cast<const _STL::BfmeWideString *>(g_009DEEF0Static);
	slot->_STL::BfmeWideString::BfmeWideString(empty);
	return other;
}
