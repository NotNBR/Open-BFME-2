// ?getApparentPlayerTemplateDisplayName@GameSlot@@QBE?AVUnicodeString@@XZ
// partial score=0.95 date=2026-09-20
// cl: /O1 /EHsc
//
// ?getApparentPlayerTemplateDisplayName@GameSlot@@QBE?AVUnicodeString@@XZ
// at retail 0x003FFBB4 (116 bytes). Follows the BFME1 GameInfo.cpp donor
// verbatim: hidden random-template slots report GUI:Random/GUI:Observer
// through TheGameText->fetch (vtable slot +0x3C, as in VersionUnicode.cpp),
// otherwise the store's display name. PLAYERTEMPLATE_RANDOM/OBSERVER are
// -1/-2 per the shared header. Retail differences from the ZH layout that
// this TU honors: m_playerTemplate sits at +0x18 (ZH has m_startPos there),
// so the interior below it is padding; showRandomPlayerTemplate() reads a
// single byte at +0x1D. Callees resolve to pins: isSlotLocalAlly at
// 0x3FF7B7, getNthPlayerTemplate at 0x1FD3C6, getDisplayName at 0x449B8F.
//
// isSlotLocalAlly is declared argless-static to reproduce retail's bare
// call: every caller in this family homes the slot to EDI for its own
// later reads, and the callee takes the slot from EDI instead of the
// stack, so passing this would push a word retail never pushes.

typedef unsigned short wchar_t;

class UnicodeString;
class AsciiString;

template <typename T>
class StringBase
{
    friend class AsciiString;
    friend class UnicodeString;

private:
    StringBase() : m_data(0) {}
    StringBase(const StringBase<T> &that);

    struct Header
    {
        int ref_count;
        unsigned short length;
        unsigned short capacity;
        T data[1];
    };

    void releaseBuffer();
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
    const wchar_t *str() const { return m_data.str(); }
private:
    StringBase<wchar_t> m_data;
};

// Retail fetch call uses vtable offset 0x3c. The preceding slots are not
// reconstructed in this TU.
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

class PlayerTemplate
{
public:
    UnicodeString getDisplayName() const;
};

class PlayerTemplateStore
{
public:
    const PlayerTemplate *getNthPlayerTemplate(int index) const;
};

extern PlayerTemplateStore *ThePlayerTemplateStore;

class MultiplayerSettings
{
public:
    bool showRandomPlayerTemplate() const { return m_showRandomPlayerTemplate != 0; }
private:
    unsigned char _pad[0x1D];
    unsigned char m_showRandomPlayerTemplate;
};

extern MultiplayerSettings *TheMultiplayerSettings;

class GameSlot
{
public:
    UnicodeString getApparentPlayerTemplateDisplayName() const;
    int getApparentPlayerTemplate() const;
    static bool isSlotLocalAlly();
    int getPlayerTemplate() const { return m_playerTemplate; }
    int getOriginalPlayerTemplate() const { return m_origPlayerTemplate; }
private:
    unsigned char _pad[0x18];
    int m_playerTemplate;
    unsigned char _pad1C[0x2C - 0x1C];
    int m_origPlayerTemplate;
};

enum
{
    PLAYERTEMPLATE_RANDOM = -1,
    PLAYERTEMPLATE_OBSERVER = -2
};

// ?getApparentPlayerTemplate@GameSlot@@QBEHXZ
int GameSlot::getApparentPlayerTemplate() const
{
    if (TheMultiplayerSettings)
    {
        if (TheMultiplayerSettings->showRandomPlayerTemplate())
        {
            if (!isSlotLocalAlly())
            {
                return getOriginalPlayerTemplate();
            }
        }
    }
    return getPlayerTemplate();
}

// ?getApparentPlayerTemplateDisplayName@GameSlot@@QBE?AVUnicodeString@@XZ
UnicodeString GameSlot::getApparentPlayerTemplateDisplayName() const
{
    if (TheMultiplayerSettings)
    {
        if (TheMultiplayerSettings->showRandomPlayerTemplate())
        {
            if (getOriginalPlayerTemplate() == PLAYERTEMPLATE_RANDOM)
            {
                if (!isSlotLocalAlly())
                {
                    return TheGameText->fetch("GUI:Random");
                }
            }
        }
    }
    if (getOriginalPlayerTemplate() == PLAYERTEMPLATE_OBSERVER)
    {
        return TheGameText->fetch("GUI:Observer");
    }
    if (getPlayerTemplate() < 0)
    {
        return TheGameText->fetch("GUI:Random");
    }
    return ThePlayerTemplateStore->getNthPlayerTemplate(getPlayerTemplate())->getDisplayName();
}
