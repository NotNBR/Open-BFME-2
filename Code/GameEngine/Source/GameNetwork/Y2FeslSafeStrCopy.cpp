// cl: /O2 /DNDEBUG /MD

// FESL bounded string copy at 0x00655700 (98B) plus the string/int setter at
// 0x006557F0 (33B) that uses it. Both live in the GameSpy zone (16 and 3
// callers respectively, all in 0x65xxxx-0x67xxxx) and share the FESL assert
// channel proven by Y2FeslAddressParse.cpp: the 0x006587A0 getter hands out
// the diag object whose virtual slot 0xC reports (expression, file, line).
// Retail litters the body with the util.h path and the two assert texts
// ("src" at line 33, "strlen(src) < dstSize" at line 34); the copy itself
// rides the pre-existing _strncpy thunk pin at 0x0062983E, so no new pins.
// Spell it plain `strncpy`: C decoration turns that into `_strncpy` (the pin),
// while a manual `_strncpy` decl decorates to `__strncpy` and never resolves.

#include <string.h>

extern "C" char *strncpy(char *dst, const char *src, unsigned n);

struct Rva007EB810Diag
{
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void fail(const char *expr, const char *file, int line);
};

extern int Rva007EB810Get();

void Rva00655700(char *dst, unsigned dstSize, const char *src)
{
	if (src == 0)
		((Rva007EB810Diag *)Rva007EB810Get())->fail(
			"src",
			"..\\..\\source\\include\\fesl/internal/util.h",
			33);
	if (!(strlen(src) < dstSize))
		((Rva007EB810Diag *)Rva007EB810Get())->fail(
			"strlen(src) < dstSize",
			"..\\..\\source\\include\\fesl/internal/util.h",
			34);
	strncpy(dst, src, dstSize);
}

class Rva006557F0Holder
{
public:
	void set(const char *src, int value);

private:
	char m_pad[8];
	char m_text[28];
	int m_value;
};

void Rva006557F0Holder::set(const char *src, int value)
{
	Rva00655700(m_text, 28, src);
	m_value = value;
}

class Rva0065F0D0Holder
{
public:
	void set(const char *src);

private:
	char m_pad[16];
	char m_text[32];
};

void Rva0065F0D0Holder::set(const char *src)
{
	Rva00655700(m_text, 32, src);
}
