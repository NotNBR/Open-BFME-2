// cl: /O1 /DNDEBUG /MD /EHsc
// ?isPlayer@GameSlot@@QBE_NUUnicodeString@@@Z @0x3FFF62 (45B):
// GameSlot::isPlayer, UnicodeString by-value overload. BFME1
// GameSlotIsPlayerUnicodeThunk.cpp donor
// (reference/open-bfme-1/.../GameNetwork/GameSlotIsPlayerUnicodeThunk.cpp):
// state==SLOT_PLAYER plus name compareNoCase, explicit releaseBuffer on the
// by-value name, ret 4. BFME2 adaptations proven by the retail bytes:
// - SLOT_PLAYER is 6 (retail cmp [ecx+4],6; ZH numbers it 5).
// - m_name sits at +0x30 (retail add ecx,0x30; ZH places it at +0x28).
// Callees already settled: StringBase<G>::compareNoCase is rowed at 0x6AA4,
// StringBase<G>::releaseBuffer is pinned at 0x36E70. No new pins.

typedef int Int;
typedef bool Bool;

enum
{
	SLOT_OPEN,
	SLOT_CLOSED,
	SLOT_EASY_AI,
	SLOT_MED_AI,
	SLOT_BRUTAL_AI,
	SLOT_AI_5,
	SLOT_PLAYER
};

template <typename T>
class StringBase
{
	friend class UnicodeString;

public:
	int compareNoCase(const StringBase<T> &that) const;

private:
	void releaseBuffer();

	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};

	Header *m_data;
};

class UnicodeString
{
public:
	int compareNoCase(const UnicodeString &that) const
	{
		return ((const StringBase<unsigned short> *)this)->compareNoCase(
			*(const StringBase<unsigned short> *)&that);
	}

	void releaseBuffer()
	{
		m_data.releaseBuffer();
	}

private:
	StringBase<unsigned short> m_data;
};

class GameSlot
{
public:
	virtual void reset(void) = 0;
	Bool isPlayer(UnicodeString userName) const;

protected:
	Int m_state;
	unsigned char m_gap08[0x30 - 0x08];
	UnicodeString m_name;
};

// ?isPlayer@GameSlot@@QBE_NUUnicodeString@@@Z
Bool GameSlot::isPlayer(UnicodeString userName) const
{
	Bool result;
	if (m_state == SLOT_PLAYER && m_name.compareNoCase(userName) == 0)
		result = true;
	else
		result = false;

	userName.releaseBuffer();
	return result;
}
