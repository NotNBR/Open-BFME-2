// Character-classification members driven by three 256-entry tables: a byte
// upper table, a byte lower table, and a dword mask table. The tables are
// DIR32 operands the patcher fills, but each one is referenced from several of
// these rows, which is what makes the three-table split checkable rather than
// assumed.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/T2CtypeTableFacets.cpp); trimmed to the seven
// bodies the sweep places. The donor's remaining sibling defs (under 16B or
// ambiguous) are omitted: only declared here, never defined, so the
// find_declared_unmatched gate stays green. The donor declares t2_block_copy
// but retail reaches memmove, so the declaration is renamed to the real
// import (Import-ref verify refuses it otherwise; no pin can fix this).
typedef unsigned short T2WChar;

extern const char t2_upper_table[256];
extern const char t2_lower_table[256];
extern const unsigned int t2_mask_table[256];

extern "C" __declspec(dllimport) void *__cdecl memmove(void *dst, const void *src, unsigned int n);

struct T2NarrowCtype
{
	char toUpper(char c) const;
	const char *toLowerRange(char *low, char *high) const;
	const char *widenRange(const char *low, const char *high, char *to) const;
	const char *narrowRange(const char *low, const char *high, char dflt, char *to) const;
};

const char *T2NarrowCtype::widenRange(const char *low, const char *high, char *to) const
{
	if (high != low)
		memmove(to, low, (unsigned int)(high - low));
	return high;
}

const char *T2NarrowCtype::narrowRange(const char *low, const char *high, char, char *to) const
{
	if (high != low)
		memmove(to, low, (unsigned int)(high - low));
	return high;
}

struct T2WideCtype
{
	const T2WChar *isRange(const T2WChar *low, const T2WChar *high, unsigned int *vec) const;
	T2WChar toUpper(unsigned int c) const;
	const T2WChar *toUpperRange(T2WChar *low, T2WChar *high) const;
	T2WChar toLower(unsigned int c) const;
	const T2WChar *toLowerRange(T2WChar *low, T2WChar *high) const;
	T2WChar widen(char c) const;
	const char *widenRange(const char *low, const char *high, T2WChar *to) const;
	int narrow(T2WChar c, char dflt) const;
	const T2WChar *narrowRange(const T2WChar *low, const T2WChar *high, char dflt, char *to) const;
};

const T2WChar *T2WideCtype::isRange(const T2WChar *low, const T2WChar *high,
                                    unsigned int *vec) const
{
	while (low < high)
	{
		*vec = (*low < 0x100) ? t2_mask_table[*low] : 0;
		++low;
		++vec;
	}
	return high;
}

const char *T2WideCtype::widenRange(const char *low, const char *high, T2WChar *to) const
{
	while (low != high)
	{
		*to = (T2WChar)(signed char)*low;
		++to;
		++low;
	}
	return high;
}

const T2WChar *T2WideCtype::narrowRange(const T2WChar *low, const T2WChar *high,
                                        char dflt, char *to) const
{
	while (low != high)
	{
		T2WChar c = *low;
		++low;
		int v = ((int)(char)c == (int)c) ? (int)c : (int)dflt;
		*to = (char)v;
		++to;
	}
	return high;
}

const T2WChar *T2WideCtype::toUpperRange(T2WChar *low, T2WChar *high) const
{
	while (low < high)
	{
		T2WChar c = *low;
		*low = (c < 0x100) ? (T2WChar)(unsigned char)t2_upper_table[c] : c;
		++low;
	}
	return high;
}
