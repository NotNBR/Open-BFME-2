// cl: /O2
// Byte-identical port of BFME1 StringBase<char>::startsWithNoCase worker.
// Retail at 0x000359B0 holds the string's own length in edx and the argument
// length in ecx; the donor's noinline + named-length spelling reproduces it.
// The TU links the dynamic CRT, so _memicmp goes through the import table.
#define _DLL
#include <string.h>

#include "string_base.h"

__declspec(noinline) bool StringBase<char>::startsWithNoCase(const char *str, int len) const
{
    if (str[0] == '\0') {
        return true;
    }
    int myLen = m_data ? m_data->length : 0;
    if (myLen < len) {
        return false;
    }
    const char *data = &m_data->data[0];
    return _memicmp(data, str, len) == 0;
}
