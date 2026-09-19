// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
//
// ?invoke@Rva00958C80@@QAEJVBfmeBstrVGP@@0JJJJJJPAX@Z at retail 0x00177010
// (170B). Trimmed port of the Open-BFME-1 WebBrowserComWrappers donor: only
// the served Rva00958C80 invoke is carried (sibling invokes, force* hosts
// and callTwoStrings stay with the donor file until their own rows land).
// ?invoke@Rva00958D30@@QAEJVBfmeBstrVGP@@0@Z at retail 0x00177130 (135B):
// same drift (push 0xBD4E3C is g_bfmeIidTSA, pinned below), second body in
// this TU. The Rva00958D30 class below also carries the single-string slot
// +0x28 overload (sibling WIP, unrowed); the vtable runs to +0x44 so later
// overloads join without moving these slots.
// The near tool's single drift (push 0xBD4E3C) is the g_bfmeIidTSA address,
// pinned below; BFME1 pins the same IID (there ?g_bfmeIidTSA@@3UBfmeGuidTSA).
// Callee pins (both retail-decoded, donor-attested names):
// ?bfmeGoVGP@BfmeThingVGP@@QAEHXZ @0x176E90 (both dtor paths call it);
// _com_issue_errorex resolves already.

struct _GUID { unsigned char bytes[16]; };
typedef _GUID GUID;
struct IUnknown;

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile *);
extern void __stdcall _com_issue_errorex(long error, IUnknown *object,
	const GUID &iid);
extern GUID g_bfmeIidTSA;

// _bstr_t's Data_t: the BSTR, its reference count and its length.
class BfmeThingVGP
{
public:
	void *m_bfme00;
	void *m_bfme04;
	int m_bfme08;
	int bfmeGoVGP() throw();
};

class BfmeBstrVGP
{
public:
	BfmeThingVGP *m_data;
	BfmeBstrVGP(const char *text) throw();
	// MSVC71 _bstr_t copies retain Data_t; a shallow owning copy is invalid.
	BfmeBstrVGP(const BfmeBstrVGP &other) throw() : m_data(other.m_data)
	{ if (m_data) InterlockedIncrement((long volatile *)&m_data->m_bfme08); }
	~BfmeBstrVGP() throw()
	{
		if (m_data)
			m_data->bfmeGoVGP();
	}
};

// The browser factory interface: one call, ten slots in, taking the two names
// and the window geometry.
class Rva00958C80
{
public:
	struct Vtable
	{
		void *slot00;
		void *slot04;
		void *slot08;
		void *slot0C;
		void *slot10;
		void *slot14;
		void *slot18;
		void *slot1C;
		void *slot20;
		long (__stdcall *slot24)(Rva00958C80 *, void *, void *, long,
			long, long, long, long, long, void *);
	};

	__declspec(noinline) long invoke(BfmeBstrVGP first,
		BfmeBstrVGP second, long hwnd, long x, long y, long w, long h,
		long options, void *gamedispatch)
	{
		BfmeThingVGP *secondData = second.m_data;
		BfmeThingVGP *firstData = first.m_data;
		void *secondValue = secondData ? secondData->m_bfme00 : 0;
		void *firstValue = firstData ? firstData->m_bfme00 : 0;
		long result = vtable->slot24(this, firstValue, secondValue, hwnd,
			x, y, w, h, options, gamedispatch);
		if (result < 0)
			_com_issue_errorex(result, (IUnknown *)this, g_bfmeIidTSA);
		return result;
	}

	Vtable *vtable;
};

// ?invoke@Rva00958D30@@QAEJVBfmeBstrVGP@@0@Z at retail 0x00177130
// (135B). Second served invoke of the donor file: the two-string overload on
// the browser dispatch interface (vtable slot +0x2C). Same near-miss story as
// the Rva00958C80 row above — the only drift is the g_bfmeIidTSA address
// (push 0xBD4E3C), already pinned. The vtable is declared out to +0x44 so the
// remaining sibling overloads can join this class without reshaping it.
class Rva00958D30
{
public:
	struct Vtable
	{
		void *slot00;
		void *slot04;
		void *slot08;
		void *slot0C;
		void *slot10;
		void *slot14;
		void *slot18;
		void *slot1C;
		void *slot20;
		void *slot24;
		long (__stdcall *slot28)(Rva00958D30 *, void *);
		long (__stdcall *slot2C)(Rva00958D30 *, void *, void *);
		void *slot30;
		void *slot34;
		void *slot38;
		void *slot3C;
		void *slot40;
		long (__stdcall *slot44)(Rva00958D30 *, void *, void *);
	};

	__declspec(noinline) long invoke(BfmeBstrVGP first,
		BfmeBstrVGP second)
	{
		BfmeThingVGP *secondData = second.m_data;
		BfmeThingVGP *firstData = first.m_data;
		void *secondValue = secondData ? secondData->m_bfme00 : 0;
		void *firstValue = firstData ? firstData->m_bfme00 : 0;
		long result = vtable->slot2C(this, firstValue, secondValue);
		if (result < 0)
			_com_issue_errorex(result, (IUnknown *)this, g_bfmeIidTSA);
		return result;
	}

	__declspec(noinline) long invoke(BfmeBstrVGP arg)
	{
		BfmeThingVGP *data = arg.m_data;
		void *value = data ? data->m_bfme00 : 0;
		long result = vtable->slot28(this, value);
		if (result < 0)
			_com_issue_errorex(result, (IUnknown *)this, g_bfmeIidTSA);
		return result;
	}

	__declspec(noinline) long invoke(BfmeBstrVGP arg, void *value)
	{
		BfmeThingVGP *data = arg.m_data;
		void *text = data ? data->m_bfme00 : 0;
		long result = vtable->slot44(this, text, value);
		if (result < 0)
			_com_issue_errorex(result, (IUnknown *)this, g_bfmeIidTSA);
		return result;
	}

	Vtable *vtable;
};

// ?forceRva00958DA0@@YAJPAVRva00958D30@@VBfmeBstrVGP@@1@Z absent-from-retail
__declspec(noinline) long forceRva00958DA0(Rva00958D30 *self,
	BfmeBstrVGP first, BfmeBstrVGP second)
{
	return self->invoke(first, second);
}

// Emission host for the single-string overload (slot +0x28).
__declspec(noinline) long forceRva00958D30(Rva00958D30 *self,
	BfmeBstrVGP arg)
{
	return self->invoke(arg);
}

// forceRva00958EB0 absent-from-retail: emission host for the string-plus-pointer
// overload (slot +0x44).
__declspec(noinline) long forceRva00958EB0(Rva00958D30 *self,
	BfmeBstrVGP arg, void *value)
{
	return self->invoke(arg, value);
}

// ?forceRva00958C80@@YAJPAVRva00958C80@@VBfmeBstrVGP@@1JJJJJJJPAX@Z absent-from-retail
__declspec(noinline) long forceRva00958C80(Rva00958C80 *self,
	BfmeBstrVGP first, BfmeBstrVGP second, long hwnd, long x, long y,
	long w, long h, long options, void *gamedispatch)
{
	return self->invoke(first, second, hwnd, x, y, w, h, options,
		gamedispatch);
}
