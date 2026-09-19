// cl: /O1 /DNDEBUG /MD /EHsc
//
// ??4FileInfoStruct@MixFileCreator@@QAEAAU01@ABU01@@Z, retail 0x002174DF,
// 41 bytes.
//
// MixFileCreator's file-info record: three plain header words (CRC, data
// offset, data size) plus the entry name. The name member assigns through
// the AsciiString copy-assign fold at 0x366F0 (existing pin); the header
// words copy as plain dwords. Layout follows the Zero Hour reference
// (WWLib/mixfile.h: MixFileCreator::FileInfoStruct), whose implicit
// copy-assignment is this body's 94.6% donor (see reverse/zh_sweep/packets/
// 002174df.md). A sibling 41B body at 0x217624 is the same shape with the
// name copy-constructed instead of assigned (the copy constructor).

template <typename T>
class StringBase
{
	friend class AsciiString;

	StringBase(const StringBase &other);

	T *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString &operator=(const AsciiString &other);
};

class MixFileCreator
{
public:
	struct FileInfoStruct
	{
		FileInfoStruct &operator=(const FileInfoStruct &src);

		unsigned long CRC;			// +0x00 CRC code for embedded file
		unsigned long Offset;		// +0x04 offset from start of data section
		unsigned long Size;			// +0x08 size of data subfile
		AsciiString Filename;		// +0x0C entry name
	};
};

// ??4FileInfoStruct@MixFileCreator@@QAEAAU01@ABU01@@Z
MixFileCreator::FileInfoStruct &MixFileCreator::FileInfoStruct::operator=(const FileInfoStruct &src)
{
	CRC = src.CRC;
	Offset = src.Offset;
	Size = src.Size;
	Filename = src.Filename;
	return *this;
}
