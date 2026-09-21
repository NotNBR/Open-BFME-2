// cl: /O1 /Oy- /MD /EHsc
// ?getMap@GameInfo@@QBE?AVAsciiString@@XZ @0x23E943 (27B):
// GameInfo::getMap, out-of-line AsciiString copy of m_map at +0x40 via the
// rowed StringBase copy-ctor at 0x365F0 into the hidden return pointer.
// Called once from GameLogic::bfmePopulateGameReport at 0x2473E9 for the
// Session-Map line. Leaf, no new pins.
class AsciiString
{
public:
	AsciiString(const AsciiString &other);
	~AsciiString();
};

class GameInfo
{
public:
	unsigned char m_pad[0x40];
	AsciiString m_map;
	AsciiString getMap() const;
};

// ?getMap@GameInfo@@QBE?AVAsciiString@@XZ
AsciiString GameInfo::getMap() const
{
	return m_map;
}
