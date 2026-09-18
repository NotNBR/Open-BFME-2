// cl: /O1 /G7 /Oi- /DNDEBUG /MD
//
// StringClass::StringClass(const char *, bool), retail 0x000F0ED1, 70 bytes.
// Dedicated TU so wwstring_assign_cstr.cpp cannot see this definition.
// Empty-inits the buffer from the static, measures with _mbslen, pre-sizes
// through Get_String when flagged or non-empty, then assigns. The
// signed-length jle and the flag-first push order fall out of the natural
// spelling under the assign TU's flags.

extern "C" __declspec(dllimport) unsigned int __cdecl _mbslen(
	const char *string);

class StringClass
{
public:
	StringClass(const char *name, bool flag);

	const StringClass &operator=(const char *string);

private:
	void Get_String(int new_len, bool flag);

	static char *m_EmptyString;
	char *m_Buffer;
};

char *StringClass::m_EmptyString;

// ??0StringClass@@QAE@PBD_N@Z
StringClass::StringClass(const char *name, bool flag)
{
	int len;

	m_Buffer = m_EmptyString;
	if (name != 0)
		len = (int)_mbslen(name);
	else
		len = 0;
	if (flag || len > 0)
		Get_String(len + 1, flag);
	*this = name;
}
