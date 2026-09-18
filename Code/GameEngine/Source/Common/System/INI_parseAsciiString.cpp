// cl: /O1 /Oy- /DNDEBUG /MD /GX /Oi-
//
// ?parseAsciiString@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002F11E, 60 bytes.
// Dedicated SEH TU (same AsciiString-temp family as INI_getNextAsciiString.cpp).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/INI_stl.cpp,
// INI::parseAsciiString): verbatim store-assign of getNextAsciiString. The
// assignment routes through the copy-assign fold at 0x366F0 (existing
// ??4AsciiString pin) and the temp tears down through releaseBuffer at
// 0x36410 (existing IAE pin), exactly the writeNameKey idiom.

template <typename T>
class StringBase
{
	friend class AsciiString;

public:
	StringBase() : m_data(0) {}

private:
	StringBase(const StringBase<T> &that);
	T *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString &operator=(const AsciiString &other);
	__forceinline ~AsciiString() { releaseBuffer(); }

protected:
	void releaseBuffer();
};

class INI
{
public:
	AsciiString getNextAsciiString();
	static void parseAsciiString(INI *ini, void *instance, void *store, const void *userData);
};

// ?parseAsciiString@INI@@SAXPAV1@PAX1PBX@Z
void INI::parseAsciiString(INI *ini, void *instance, void *store, const void *userData)
{
	*(AsciiString *)store = ini->getNextAsciiString();
}
