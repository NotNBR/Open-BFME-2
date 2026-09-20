// cl: /O2 /MD
// Retail 0x00689380 (69B). Three-string-plus-POD record copy ctor: each
// string member copy-assigns through the shared AsciiString copy-assignment
// body at 0x366F0 (NOT the 0x365F0 ctor family), then the bytes and dwords
// copy inline. Transferred from the BFME1 reconstruction
// (Rva000C3380Copy.cpp); member layout and call shape match retail exactly.
// The trivial default ctor below exists only so the members can default
// before the body assignments; retail never calls it.

// ??0AsciiString@@QAE@XZ absent-from-retail
class AsciiString
{
public:
	AsciiString() {}
	AsciiString &operator=(const AsciiString &other);

private:
	char *m_data;
};

class Rva000C3380
{
	AsciiString m_00;
	AsciiString m_04;
	AsciiString m_08;
	char m_0C;
	int m_10;
	char m_14;
	int m_18;

public:
	Rva000C3380(const Rva000C3380 &other);
};

// ??0Rva000C3380@@QAE@ABV0@@Z
Rva000C3380::Rva000C3380(const Rva000C3380 &other)
{
	m_00 = other.m_00;
	m_04 = other.m_04;
	m_08 = other.m_08;
	m_0C = other.m_0C;
	m_10 = other.m_10;
	m_14 = other.m_14;
	m_18 = other.m_18;
}
