// cl: /O1 /DNDEBUG /MD /EHsc
// Retail RVA 0x00300C7E, 142 bytes (the reloc size 10 is stale).
// MapMetaData::bfme_getDisplayName, the player-count-suffixed display-name
// getter called by AptMapPreview::bfmeSetMapTitle. The base name comes from
// the sibling bfme_getBaseDisplayName TU; when requested and the count reaches
// two, a " (%d)" suffix is formatted (UnicodeString::format is a __cdecl
// member, so this rides the stack: push count, push format, push this) and
// concatenated. Layout shared with that TU: label +0x00, count +0x20,
// file name +0x50, cached base name +0xF8. Every out-of-line copy this TU
// emits matches its string_base/unicode_string row and folds.

typedef unsigned short WideChar;

template <typename T> class StringBase
{
	friend class UnicodeString;
	friend class MapMetaData;
public:
	void concat(const StringBase<T> &other);
private:
	StringBase() { m_data = 0; }
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	void *m_data;
};

class UnicodeString : private StringBase<unsigned short>
{
	friend class MapMetaData;
public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
	~UnicodeString() {}
	void __cdecl format(const WideChar *format, ...);
};

class AsciiString
{
	void *m_data;
};

class MapMetaData
{
public:
	UnicodeString bfme_getBaseDisplayName();
	UnicodeString bfme_getDisplayName(bool includePlayerCount);

private:
	UnicodeString m_displayNameLabel;
	char m_pad04[0x20 - 0x04];
	int m_playerCount;
	char m_pad24[0x50 - 0x24];
	AsciiString m_fileName;
	char m_pad54[0xF8 - 0x54];
	UnicodeString m_cachedBaseDisplayName;
};

UnicodeString MapMetaData::bfme_getDisplayName(bool includePlayerCount)
{
	UnicodeString name = bfme_getBaseDisplayName();
	if (includePlayerCount && m_playerCount >= 2)
	{
		UnicodeString suffix;
		suffix.format(L" (%d)", m_playerCount);
		((StringBase<WideChar> &)name).concat(suffix);
	}
	return name;
}
