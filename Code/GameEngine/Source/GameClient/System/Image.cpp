// cl: /O1 /DNDEBUG /MD

// Image::clearStatus, retail 0x002D8E72 (17B).
// Ported from Open-BFME-1 Code/GameEngine/Source/GameClient/System/Image.cpp
// (BFME1 0x005D1C30). Member offsets follow the proven ImageCtor TU in this
// directory (m_status at +0x30).

class AsciiString
{
public:
	AsciiString() : m_data(0) {}

private:
	void *m_data;
};

struct ICoord2D
{
	int x;
	int y;
};

struct Coord2D
{
	float x;
	float y;
};

struct Region2D
{
	Coord2D lo;
	Coord2D hi;
};

class Image
{
public:
	virtual ~Image();
	unsigned int clearStatus(unsigned int bit);

private:
	AsciiString m_name;
	AsciiString m_filename;
	ICoord2D m_textureSize;
	Region2D m_UVCoords;
	ICoord2D m_imageSize;
	void *m_rawTextureData;
	unsigned int m_status;
};

// ?clearStatus@Image@@QAEII@Z, retail 0x002D8E72 (17B).
unsigned int Image::clearStatus(unsigned int bit)
{
	unsigned int prevStatus = m_status;

	m_status &= ~bit;
	return prevStatus;
}
