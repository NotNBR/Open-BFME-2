// cl: /DNDEBUG /MD /Oy- /EHsc
//
// Debug::operator<<(__int64), retail 0x0003B510, 83 bytes. Trimmed port of
// the Open-BFME-1 debug_operator_long donor (b1 0x0088C290): only the i64
// overload is carried; sibling overloads stay with the donor until rows land.
// Two BFME2 adaptations:
// - m_prefix sits at +0x9E7C (m_radix +0x9E8C), 0xC past the donor layout,
//   read straight off the retail lea/mov (8d 96 7c 9e / 8b 86 8c 9e).
// - AddOutput is private VIRTUAL (established ?AddOutput@Debug@@EAEXPBDI@Z
//   pin at 0x39B70, already in the ledger), so the call is Debug::-qualified
//   to keep the direct near-call retail shows. No new pins.

#include <stdlib.h>
#include <string.h>

class Debug
{
public:
	virtual ~Debug();
	virtual void pad01();
	virtual void pad02();
	virtual void pad03();
	virtual void pad04();
	virtual void pad05();
	virtual void pad06();
	virtual void pad07();
	virtual void pad08();
	virtual void pad09();
	virtual void pad10();
	virtual void pad11();
	virtual void pad12();
	virtual void pad13();
	virtual Debug &operator<<(char const *);
	Debug &operator<<(long);
	Debug &operator<<(unsigned);
	Debug &operator<<(unsigned long);
	Debug &operator<<(__int64);
	Debug &operator<<(unsigned __int64);
	Debug &operator<<(bool);
	char m_pad[0x9e78];
	char m_prefix[16];
	int m_radix;
private:
	virtual void AddOutput(const char *, unsigned);
};

// Debug::operator<<(signed __int64), retail at 0x0003B510
Debug &Debug::operator<<(__int64 val)
{
	char help[64 + 1];
	Debug::AddOutput(m_prefix, strlen(m_prefix));
	return (*this) << _i64toa(val, help, m_radix);
}

// Debug::operator<<(unsigned __int64), retail at 0x0003B570. Same shape as
// the signed twin above; the CRT worker is _ui64toa (IAT 0x00BBA590 vs the
// signed 0x00BBA594) and the layout is this TU's adapted one.
Debug &Debug::operator<<(unsigned __int64 val)
{
	char help[64 + 1];
	Debug::AddOutput(m_prefix, strlen(m_prefix));
	return (*this) << _ui64toa(val, help, m_radix);
}
