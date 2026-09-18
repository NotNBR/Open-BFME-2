// cl: /O1 /G7 /Oi- /DNDEBUG /MD
//
// StringClass::StringClass(int, bool), retail 0x00065F34, 39 bytes.
// Dedicated TU so no other unit sees this definition. Snapshot-name temp
// ctor used by the DX8 cached-state setters as (0, true): empty-inits the
// buffer from the static, pre-sizes through Get_String, then stamps the
// lead byte from the global. Straight-line flow stays frameless under the
// assign TU's flags.

class StringClass
{
public:
	StringClass(int value, bool flag);

private:
	void Get_String(int new_len, bool flag);

	static char *m_EmptyString;
	static char m_LeadByte;
	char *m_Buffer;
};

char *StringClass::m_EmptyString;
char StringClass::m_LeadByte;

// ??0StringClass@@QAE@H_N@Z
StringClass::StringClass(int value, bool flag)
{
	m_Buffer = m_EmptyString;
	Get_String(value, flag);
	m_Buffer[0] = m_LeadByte;
}
