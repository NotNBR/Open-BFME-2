// cl: /DNDEBUG /MD /EHs-c-
//
// File-static wchar skipSeps / skipNonSeps for StringBase<wchar_t>::nextToken.
// Retail calls them with the string in EAX and the separator set in EBX.

static unsigned short *skipSepsW(unsigned short *p, const unsigned short *seps);
static unsigned short *skipNonSepsW(unsigned short *p, const unsigned short *seps);

// The real 197-byte nextToken at BFME2 RVA 0x00037830 replaces the shape-only
// host. Its BFME1 counterpart establishes identity; retail establishes the
// copy, remainder length and release paths. Keeping both helpers in this TU
// reproduces MSVC's EAX/EBX private calling convention.
// getBufferForRead: export ordinal 1646 and CALL at 0x37887 -> 0x370A0.
// TU-local declarations keep this reconstruction independent of shared shims.
#include <string.h>

template <typename T>
class StringBase
{
public:
    bool nextToken(StringBase<T> *out, const T *seps);
    T *getBufferForRead(int len);
    void set(const T *str, int len);
private:
    void releaseBuffer();
    struct Header {
        int ref_count;
        unsigned short length;
        unsigned short capacity;
        T data[1];
    };
    Header *m_data;
};

template <>
bool StringBase<unsigned short>::nextToken(StringBase<unsigned short> *out, const unsigned short *seps)
{
    Header *data = m_data;
    if (data == 0 || data->length == 0 || out == this)
        return false;
    static const unsigned short kDefault[] = { ' ', '\n', '\r', '\t', 0 };
    if (seps == 0)
        seps = kDefault;
    unsigned short *start = skipSepsW(data->data, seps);
    unsigned short *end = skipNonSepsW(start, seps);
    if (end > start) {
        int len = (int)(end - start);
        unsigned short *dest = out->getBufferForRead(len);
        memcpy(dest, start, len * sizeof(unsigned short));
        dest[len] = 0;
        int total = m_data ? m_data->length : 0;
        set(end, total - (int)(end - m_data->data));
        return true;
    }
    releaseBuffer();
    out->releaseBuffer();
    return false;
}

static unsigned short *skipSepsW(unsigned short *p, const unsigned short *seps)
{
	unsigned short c = *p;
	if (!c)
		return p;
	while (c)
	{
		unsigned short first = *seps;
		const unsigned short *s = seps;
		if (!first)
			return p;
		unsigned short sc = first;
		do
		{
			if (sc == c)
				goto advance;
			sc = *++s;
		} while (sc);
		return p;
	advance:
		c = *++p;
	}
	return p;
}

static unsigned short *skipNonSepsW(unsigned short *p, const unsigned short *seps)
{
	unsigned short c = *p;
	if (!c)
		return p;
	for (;;)
	{
		unsigned short first = *seps;
		const unsigned short *s = seps;
		if (!first)
			goto advance;
		unsigned short sc = first;
		while (sc != c)
		{
			sc = *++s;
			if (!sc)
				goto advance;
		}
		return p;
	advance:
		c = *++p;
		if (!c)
			return p;
	}
}
