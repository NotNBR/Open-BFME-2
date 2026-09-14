// ?openDataChunk@DataChunkOutput@@QAEXPADG@Z
// partial score=0.9 date=2026-09-14
// cl: /O1 /EHsc
// cl: /O1 /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /MD
//
// DataChunkOutput::openDataChunk, retail 0x00307C76 (179 bytes).
// Ported from the exact BFME1 reconstruction
// (Code/GameEngine/Source/Common/System/DataChunkOutput.cpp), ZH
// DataChunk.cpp unchanged. Retail proves the layout: m_tmp_file at +4,
// m_contents at +8, m_chunkStack at +0x18; OutputChunk is 0x10 bytes
// (vtable + next + id + filepos) with vtable 0xC07E80; version is an
// unsigned short (fwrite size 2, retail 0x307CEB-0x307CF3), id 4 bytes.
// Callees StringBase ctor/operator new resolve via the ledger; allocateID
// is pinned from this call site's shape (m_contents + AsciiString temp).

#include <stdio.h>

typedef int Int;
typedef unsigned short UnsignedShort;

struct BfmeStringData
{
	UnsignedShort m_refCount;
	UnsignedShort m_numCharsAllocated;
	UnsignedShort m_len;
	UnsignedShort m_pad;
};

class AsciiString;
template <typename T>
class StringBase
{
	friend class AsciiString;
private:
	StringBase(const StringBase<T> &);
	StringBase(const T *);
	~StringBase();
	void concat(const T *, int);
	BfmeStringData *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

class Mapping;
class DataChunkTableOfContents
{
public:
	unsigned int allocateID(const AsciiString &name);
private:
	Mapping *m_list;
	int m_listLength;
	unsigned int m_nextID;
	bool m_headerOpened;
};

class OutputStream;
class OutputChunk
{
public:
	virtual ~OutputChunk();
	OutputChunk *next;
	unsigned int id;
	int filepos;
};

class DataChunkOutput
{
public:
	void openDataChunk(char *name, unsigned short version);
private:
	OutputStream *m_pOut;
	FILE *m_tmp_file;
	DataChunkTableOfContents m_contents;
	OutputChunk *m_chunkStack;
};

// ?openDataChunk@DataChunkOutput@@QAEXPADG@Z
void DataChunkOutput::openDataChunk(char *name, unsigned short version)
{
	unsigned int id;
	{
		const AsciiString &chunkName = AsciiString(name);
		id = m_contents.allocateID(chunkName);
	}

	OutputChunk *chunk = new OutputChunk;
	chunk->next = m_chunkStack;
	m_chunkStack = chunk;
	chunk->id = id;

	fwrite(&id, sizeof(id), 1, m_tmp_file);
	fwrite(&version, sizeof(version), 1, m_tmp_file);
	chunk->filepos = ftell(m_tmp_file);

	int dummy = 0xffff;
	fwrite(&dummy, sizeof(dummy), 1, m_tmp_file);
}
