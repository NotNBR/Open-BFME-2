// Word-int getters: eight-byte __thiscall members with one shape:
//
//     movzx eax,word ptr [ecx+<DISP>] / ret
//
// One word is read at a fixed displacement from `this`, zero-extended, and
// returned as an int. Unlike DispWordFieldGetters (which returns
// unsigned short via mov ax), these return int, so MSVC 7.1 emits movzx.
// Class names are address-derived (identity unrecoverable from 8 bytes);
// member names positional. No // cl: line (defaults match the shape).

class Rva0028A952WordIntField
{
public:
	int get() const;

private:
	char m_pad[0x5DE];
	unsigned short m_value; // +0x5DE
};

// ?get@Rva0028A952WordIntField@@QBEHXZ
int Rva0028A952WordIntField::get() const
{
	return m_value;
}

class Rva0006E185WordIntField
{
public:
	int get() const;

private:
	char m_pad[0x5E2];
	unsigned short m_value; // +0x5E2
};

// ?get@Rva0006E185WordIntField@@QBEHXZ
int Rva0006E185WordIntField::get() const
{
	return m_value;
}
