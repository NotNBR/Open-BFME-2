// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
//
// ?invoke@Rva00958C80@@QAEJVBfmeBstrVGP@@0JJJJJJPAX@Z at retail 0x00177010
// (170B). Trimmed port of the Open-BFME-1 WebBrowserComWrappers donor: only
// the served Rva00958C80 invoke is carried (sibling invokes, force* hosts
// and callTwoStrings stay with the donor file until their own rows land).
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

// ?forceRva00958C80@@YAJPAVRva00958C80@@VBfmeBstrVGP@@1JJJJJJJPAX@Z absent-from-retail
__declspec(noinline) long forceRva00958C80(Rva00958C80 *self,
	BfmeBstrVGP first, BfmeBstrVGP second, long hwnd, long x, long y,
	long w, long h, long options, void *gamedispatch)
{
	return self->invoke(first, second, hwnd, x, y, w, h, options,
		gamedispatch);
}
