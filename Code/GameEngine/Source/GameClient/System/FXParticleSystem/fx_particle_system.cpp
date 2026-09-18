namespace FXParticleSystem
{
class EventModuleInfo
{
public:
    EventModuleInfo();
    EventModuleInfo &operator=(const EventModuleInfo &that);

protected:
    ~EventModuleInfo();

private:
    bool m_unk0;
    bool m_unk1;
};

EventModuleInfo::EventModuleInfo()
{
    m_unk0 = true;
    m_unk1 = true;
}

EventModuleInfo::~EventModuleInfo()
{
}

class ParticleSystemInfo
{
public:
    virtual const char *GetSnapshotName();
};

const char *ParticleSystemInfo::GetSnapshotName()
{
    return "FXParticleSystemInfo";
}

// LineEmissionVolumeInfo copy ctor, retail 0x003A653B (63B). BFME1 donor
// b1 0x005D5A90: base EmissionVolumeInfo copy (inlined: base vtable +
// flag byte) then the derived vtable and the six float copies. No
// out-of-line calls, so no pins. Snapshot is vtable-only here (4 bytes),
// which seats m_flag at +0x4 and the float block at +0x8 per retail.
class Snapshot
{
public:
    virtual ~Snapshot();
};

class EmissionVolumeInfo : public Snapshot
{
public:
    virtual ~EmissionVolumeInfo();

    bool m_flag;
};

class LineEmissionVolumeInfo : public EmissionVolumeInfo
{
public:
    LineEmissionVolumeInfo(const LineEmissionVolumeInfo &that);

private:
    float m_unk[6];
};

// ??0LineEmissionVolumeInfo@FXParticleSystem@@QAE@ABV01@@Z
LineEmissionVolumeInfo::LineEmissionVolumeInfo(const LineEmissionVolumeInfo &that)
    : EmissionVolumeInfo(that)
{
    m_unk[0] = that.m_unk[0];
    m_unk[1] = that.m_unk[1];
    m_unk[2] = that.m_unk[2];
    m_unk[3] = that.m_unk[3];
    m_unk[4] = that.m_unk[4];
    m_unk[5] = that.m_unk[5];
}
}
