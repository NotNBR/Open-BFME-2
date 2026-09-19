// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX
//
// BFME2 DataChunkInput version getter, transferred from the exact BFME1
// reconstruction (Code/GameEngine/Source/Common/System/DataChunk.cpp).
// Retail BFME2 keeps the same shape: null chunk stack reads zero, otherwise
// the version word at chunk+0xC with the stack head at this+0x1C.

struct InputChunk
{
	unsigned char m_pre[0x0C];
	unsigned short m_version;	// +0x0C
};

class DataChunkInput
{
public:
	unsigned short getChunkVersion();

private:
	unsigned char m_pre[0x1C];
	InputChunk *m_chunkStack;	// +0x1C
};

// ?getChunkVersion@DataChunkInput@@QAEGXZ
unsigned short DataChunkInput::getChunkVersion()
{
	if (m_chunkStack == 0)
		return 0;

	return m_chunkStack->m_version;
}

// Table of contents for the chunk-name registry. Layout mirrors the ZH
// DataChunkTableOfContents (list head, entry count, next ID allocator,
// header-open flag); declaration order is what the bytes prove: retail
// stores NULL, 0, 1, false in that order.
class DataChunkTableOfContents
{
public:
	DataChunkTableOfContents();

	void *m_list;				// +0x00
	int m_listLength;			// +0x04
	unsigned int m_nextID;		// +0x08
	bool m_headerOpened;		// +0x0C
};

// ??0DataChunkTableOfContents@@QAE@XZ
DataChunkTableOfContents::DataChunkTableOfContents() :
	m_list(0),
	m_nextID(1),
	m_listLength(0),
	m_headerOpened(false)
{
}
