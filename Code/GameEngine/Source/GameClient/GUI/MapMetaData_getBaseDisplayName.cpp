// cl: /O1 /DNDEBUG /MD /EHsc
// Retail RVA 0x00300AEA, 404 bytes.
// MapMetaData::bfme_getBaseDisplayName, the lazy cached map.str base-name
// loader feeding bfme_getDisplayName. Ported from Open-BFME-1
// (Code/GameEngine/Source/GameClient/MapMetaData_getBaseDisplayName.cpp)
// with two BFME2 differences: the fallback translates the leaf then strips a
// trailing ".map" (endsWith plus four removeLastChar calls, 0x000376E0 pinned
// under the narrow-pin's wide twin), and the suffix format lives in the
// numbered wrapper. Layout measured from retail: display-name label +0x00,
// player count +0x20, file name +0x50, cached base name +0xF8.
// StringBase friends let the body call the base methods directly so no novel
// wrapper is emitted; every out-of-line copy this TU emits (default/copy/
// substring ctors, both dtors, str, getLength) is byte-identical to its
// string_base/unicode_string/ascii_string row and folds. TheGameText virtuals
// need no pins (slots reset +0x24, fetch +0x38, initMapStringFile +0x4C);
// TheGameText itself is declared extern like VersionUnicode.cpp does.

typedef unsigned short WideChar;

template <typename T> class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
	friend class MapMetaData;
public:
	int getLength() const { return m_data ? m_data->length : 0; }
	const T *str() const { return m_data ? (const T *)((const char *)m_data + 8) : (const T *)""; }
	const T *reverseFind(T c) const;
	void concat(const T *text);
	void set(const StringBase<T> &other);
	bool endsWith(const T *text) const;
	void removeLastChar();
private:
	StringBase() { m_data = 0; }
	StringBase(const StringBase<T> &other);
	StringBase(const StringBase<T> &other, int start, int len);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	struct Header
	{
		int refCount;
		unsigned short length;
		unsigned short capacity;
		T text[1];
	};
	Header *m_data;
};

class UnicodeString;

class AsciiString : private StringBase<char>
{
	friend class MapMetaData;
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	AsciiString(const AsciiString &other, int start, int len) : StringBase<char>(other, start, len) {}
	~AsciiString() {}
	void translate(const WideChar *text);
	void translate(const UnicodeString &text);
};

class UnicodeString : private StringBase<WideChar>
{
	friend class MapMetaData;
public:
	UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
	~UnicodeString() {}
	void translate(const char *text);
};

class GameTextInterface
{
public:
	virtual ~GameTextInterface() {}
	virtual void slot04() = 0;
	virtual void slot08() = 0;
	virtual void slot0C() = 0;
	virtual void slot10() = 0;
	virtual void slot14() = 0;
	virtual void slot18() = 0;
	virtual void slot1C() = 0;
	virtual void slot20() = 0;
	virtual void reset() = 0;
	virtual void slot28() = 0;
	virtual void slot2C() = 0;
	virtual void slot30() = 0;
	virtual void slot34() = 0;
	virtual UnicodeString fetch(const AsciiString &label, bool *exists = 0) = 0;
	virtual void slot3C() = 0;
	virtual void slot40() = 0;
	virtual void slot44() = 0;
	virtual void slot48() = 0;
	virtual void initMapStringFile(const AsciiString &filename) = 0;
};

extern GameTextInterface *TheGameText;

class MapMetaData
{
public:
	UnicodeString bfme_getBaseDisplayName();

private:
	UnicodeString m_displayNameLabel;
	char m_pad04[0x20 - 0x04];
	int m_playerCount;
	char m_pad24[0x50 - 0x24];
	AsciiString m_fileName;
	char m_pad54[0xF8 - 0x54];
	UnicodeString m_cachedBaseDisplayName;
};

UnicodeString MapMetaData::bfme_getBaseDisplayName()
{
	if (m_cachedBaseDisplayName.getLength() == 0)
	{
		const char *slash = ((StringBase<char> &)m_fileName).reverseFind('\\');
		if (slash)
		{
			AsciiString stringFileName(m_fileName, 0,
				(int)(slash - ((StringBase<char> &)m_fileName).str()) + 1);
			((StringBase<char> &)stringFileName).concat("map.str");
			TheGameText->initMapStringFile(stringFileName);
		}

		AsciiString label;
		if (*m_displayNameLabel.str() == '$')
		{
			label.translate(m_displayNameLabel.str() + 1);
		}
		else
		{
			label.translate(m_displayNameLabel);
		}

		bool exists = false;
		m_cachedBaseDisplayName.set(TheGameText->fetch(label, &exists));
		if (!exists)
		{
			if (slash && *m_displayNameLabel.str() == '$')
			{
				m_cachedBaseDisplayName.translate(slash + 1);
				if (((StringBase<WideChar> &)m_cachedBaseDisplayName).endsWith(L".map"))
				{
					for (int i = 4; i != 0; --i)
						((StringBase<WideChar> &)m_cachedBaseDisplayName).removeLastChar();
				}
			}
			else
			{
				m_cachedBaseDisplayName.set(m_displayNameLabel);
			}
		}

		TheGameText->reset();
	}

	return m_cachedBaseDisplayName;
}
