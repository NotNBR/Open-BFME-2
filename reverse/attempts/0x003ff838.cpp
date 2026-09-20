// ?getApparentColor@GameSlot@@QBEHXZ
// partial score=0.9 date=2026-09-20
// cl: /O1 /G7 /DNDEBUG /MD /EHsc

// GameSlot apparent-* family plus the two slot predicates it shares a page
// with. BFME1 GameInfo.cpp donor (reference/open-bfme-1/.../GameNetwork/
// GameInfo.cpp): the four apparent accessors hide a network opponent's true
// slot behind the original values unless the slot is a local ally, and the
// display-name variant falls back to GUI:Random / GUI:Observer fetched from
// the string manager. Retail outlines the ally test into its own 92B body;
// because every caller lives in this TU, MSVC's same-TU private convention
// carries the slot in EDI with a bare call and the callers home `this` into
// EDI for their own post-call reads.

typedef int Int;
typedef bool Bool;

enum { MAX_SLOTS = 8 };

// BFME2 numbers the human slot state as 6: retail isHuman bodies compare
// m_state against 6. The earlier states are not named here.
enum { SLOT_PLAYER = 6 };

enum
{
    PLAYERTEMPLATE_RANDOM = -1,
    PLAYERTEMPLATE_OBSERVER = -2
};

typedef unsigned short WideChar;

class AsciiString;
class UnicodeString;

template <typename T>
class StringBase
{
    friend class AsciiString;
    friend class UnicodeString;

private:
    StringBase() : m_data(0) {}
    StringBase(const StringBase<T> &that);

    void releaseBuffer();

    struct Header
    {
        int ref_count;
        unsigned short length;
        unsigned short capacity;
        T data[1];
    };

    Header *m_data;

public:
    const T *str() const
    {
        static const T TheNullChr = 0;
        return m_data ? &m_data->data[0] : &TheNullChr;
    }
};

class AsciiString
{
public:
    AsciiString(const AsciiString &that) : m_data(that.m_data) {}
    ~AsciiString() { m_data.releaseBuffer(); }

private:
    StringBase<char> m_data;
};

class UnicodeString
{
public:
    UnicodeString() {}
    UnicodeString(const UnicodeString &that) : m_data(that.m_data) {}
    ~UnicodeString() { m_data.releaseBuffer(); }
    const WideChar *str() const { return m_data.str(); }

private:
    StringBase<WideChar> m_data;
};

// Retail fetch calls use vtable offset 0x3c. The fourteen preceding
// non-destructor methods have not yet been reconstructed in this TU.
class GameTextInterface
{
public:
    virtual ~GameTextInterface() {}
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0c() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1c() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2c() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual UnicodeString fetch(const char *label, bool *exists = 0) = 0;
};

extern GameTextInterface *TheGameText;

class MultiplayerColorDefinition
{
public:
    Int getColor() const { return m_color; }

private:
    AsciiString m_tooltipName;
    float m_rgbValue[3];
    Int m_color;
};

class MultiplayerSettings
{
public:
    Bool showRandomPlayerTemplate() const { return m_showRandomPlayerTemplate; }
    Bool showRandomStartPos() const { return m_showRandomStartPos; }
    Bool showRandomColor() const { return m_showRandomColor; }
    MultiplayerColorDefinition *getColor(Int which);

private:
    char m_pad[0x1D];
    Bool m_showRandomPlayerTemplate;
    Bool m_showRandomStartPos;
    Bool m_showRandomColor;
};

extern MultiplayerSettings *TheMultiplayerSettings;

class PlayerTemplate
{
public:
    UnicodeString getDisplayName() const;
};

class PlayerTemplateStore
{
public:
    const PlayerTemplate *getNthPlayerTemplate(Int which) const;
};

extern PlayerTemplateStore *ThePlayerTemplateStore;

class GameInfo;

class GameSlot
{
public:
    virtual void reset();

    Bool isHuman() const { return m_state == SLOT_PLAYER; }
    Int getTeamNumber() const { return m_teamNumber; }
    Int getOriginalPlayerTemplate() const { return m_origPlayerTemplate; }

    Int getApparentPlayerTemplate() const;
    Int getApparentColor() const;
    Int getApparentStartPos() const;
    UnicodeString getApparentPlayerTemplateDisplayName() const;

    void unAccept();
    void setMapAvailability(Bool hasMap);

private:
    // Banked pin ?isSlotLocalAlly@GameSlot@@SA_NXZ @0x003FF7B7: retail
    // passes the slot in EDI with a bare call, so the declaration takes no
    // source-level argument; the body is reconstructed separately.
    static Bool isSlotLocalAlly();

    // +0x00 vtable (virtual reset above).
    Int m_state;                    // +0x04
    Bool m_isAccepted;              // +0x08
    Bool m_hasMap;                  // +0x09
    char m_pad0A[2];                // +0x0A
    Int m_color;                    // +0x0C
    Int m_startPos;                 // +0x10
    char m_pad14[4];                // +0x14
    Int m_playerTemplate;           // +0x18
    Int m_teamNumber;               // +0x1C
    char m_pad20[4];                // +0x20
    Int m_origColor;                // +0x24
    Int m_origStartPos;             // +0x28
    Int m_origPlayerTemplate;       // +0x2C
};

class GameInfo
{
public:
    // Retail reaches getLocalSlotNum through vtable slot 13 (+0x34). The
    // twelve middle slots have not yet been reconstructed in this TU.
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0c() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1c() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2c() = 0;
    virtual void slot30() = 0;
    virtual Int getLocalSlotNum() const = 0;

    const GameSlot *getConstSlot(Int slotNum) const;

private:
    // vfptr (+0x00) then pads so the slot array lands at +0x18.
    char m_pad[0x14];
    GameSlot *m_slot[MAX_SLOTS];
};

extern GameInfo *TheGameInfo;

// ?getConstSlot@GameInfo@@QBEPBVGameSlot@@H@Z
const GameSlot *GameInfo::getConstSlot(Int slotNum) const
{
    if (slotNum < 0 || slotNum >= MAX_SLOTS)
        return 0;
    return m_slot[slotNum];
}


// ?getApparentPlayerTemplate@GameSlot@@QBEHXZ
Int GameSlot::getApparentPlayerTemplate() const
{
    if (TheMultiplayerSettings && TheMultiplayerSettings->showRandomPlayerTemplate() &&
        !isSlotLocalAlly())
    {
        return m_origPlayerTemplate;
    }
    return m_playerTemplate;
}



// ?getApparentColor@GameSlot@@QBEHXZ
Int GameSlot::getApparentColor() const
{
    if (TheMultiplayerSettings && m_origPlayerTemplate == PLAYERTEMPLATE_OBSERVER)
        return TheMultiplayerSettings->getColor(PLAYERTEMPLATE_OBSERVER)->getColor();

    if (TheMultiplayerSettings && TheMultiplayerSettings->showRandomColor() &&
        !isSlotLocalAlly())
    {
        return m_origColor;
    }
    return m_color;
}

// ?getApparentStartPos@GameSlot@@QBEHXZ
Int GameSlot::getApparentStartPos() const
{
    if (TheMultiplayerSettings && TheMultiplayerSettings->showRandomStartPos() &&
        !isSlotLocalAlly())
    {
        return m_origStartPos;
    }
    return m_startPos;
}

// ?getApparentPlayerTemplateDisplayName@GameSlot@@QBE?AVUnicodeString@@XZ
UnicodeString GameSlot::getApparentPlayerTemplateDisplayName() const
{
    if (TheMultiplayerSettings && TheMultiplayerSettings->showRandomPlayerTemplate() &&
        m_origPlayerTemplate == PLAYERTEMPLATE_RANDOM && !isSlotLocalAlly())
    {
        return TheGameText->fetch("GUI:Random");
    }
    else if (m_origPlayerTemplate == PLAYERTEMPLATE_OBSERVER)
    {
        return TheGameText->fetch("GUI:Observer");
    }
    if (m_playerTemplate < 0)
    {
        return TheGameText->fetch("GUI:Random");
    }
    return ThePlayerTemplateStore->getNthPlayerTemplate(m_playerTemplate)->getDisplayName();
}

// ?unAccept@GameSlot@@QAEXXZ
void GameSlot::unAccept()
{
    if (isHuman())
    {
        m_isAccepted = false;
    }
}

// ?setMapAvailability@GameSlot@@QAEX_N@Z
void GameSlot::setMapAvailability(Bool hasMap)
{
    if (isHuman())
    {
        m_hasMap = hasMap;
    }
}

