// cl: /O2 /DNDEBUG /MD
//
// BfmeMsgVJH::BfmeMsgVJH, retail 0x00655900 (76 bytes).
// EA FESL game-browser message: base subobject (retail vtable 0xCE0BC4,
// one field; the 16B body at 0x00655770 is shared verbatim with the
// PrototypeClass ctor row via ICF) plus buffer/size members at +0x10/+0x14
// (same slots Y2ScalarDeleters.cpp names m_field10/m_field14), zeroed
// header/trailer words, a count of 4 at +0x2C and the NUL/link flag.
// The base is polymorphic in retail; it is declared without virtuals here
// because only its ctor address reaches codegen.

class BfmeMsg
{
public:
	BfmeMsg();
	virtual ~BfmeMsg();

protected:
	int m_state;
};

class BfmeMsgVJH : public BfmeMsg
{
public:
	BfmeMsgVJH(char *buffer, int size) throw();
	virtual ~BfmeMsgVJH();

private:
	int m_field08;
	int m_field0C;
	char *m_buffer;
	int m_size;
	int m_field18;
	int m_field1C;
	int m_field20;
	int m_field24;
	int m_field28;
	int m_count;
	char m_flag;
	char m_pad31[3];
};

BfmeMsgVJH::BfmeMsgVJH(char *buffer, int size) throw()
{
	// Store order scheduled to match retail codegen (see explain_mismatch).
	m_field08 = 0;
	m_field0C = 0;
	m_state = 0;
	m_buffer = buffer;
	m_size = size;
	m_field18 = 0;
	m_field28 = 0;
	m_field24 = 0;
	m_field20 = 0;
	m_field1C = 0;
	if (buffer != 0)
		buffer[0] = 0;
	m_flag = 0;
	m_count = 4;
}
