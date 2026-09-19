// cl: /O1 /DNDEBUG /MD
// BFME1's cached status query, adapted to BFME2's out-of-line cache setter.
enum WeaponStatus
{
    READY_TO_FIRE,
    OUT_OF_AMMO,
    BETWEEN_FIRING_SHOTS,
    RELOADING_CLIP,
    PRE_ATTACK,
    WEAPON_STATUS_5
};

class ObjectFilter
{
public:
    bool isValid() const;
};

class WeaponTemplate
{
public:
    char m_pad00[0x78];
    int m_flag78;
    char m_pad7C[0x120 - 0x78 - 4];
    ObjectFilter m_ammo;
};

struct GameLogicFrame
{
    char m_pad00[0x40];
    unsigned int m_frame;
};

#define TheGameLogic (*(GameLogicFrame **)0x00DFE78C)

class Weapon
{
public:
    WeaponStatus getStatus() const;
    WeaponStatus computeStatus(bool *cacheable) const;
    __declspec(noinline) void cacheStatus(WeaponStatus status) const;
    unsigned int getRemainingAmmo(bool countReloadingAsEmpty) const;
    bool isAmmoReady() const;
private:
    char m_pad00[4];
    WeaponTemplate *m_template;
    char m_pad08[8];
    mutable WeaponStatus m_status;
    int m_pad14;
    unsigned int m_frame18;
    unsigned int m_frame1C;
    unsigned int m_frame20;
};

void Weapon::cacheStatus(WeaponStatus status) const
{
    if (m_status != status)
        m_status = status;
}

WeaponStatus Weapon::getStatus() const
{
    bool cacheable = true;
    WeaponStatus status = computeStatus(&cacheable);
    if (cacheable)
        cacheStatus(status);
    return status;
}

WeaponStatus Weapon::computeStatus(bool *cacheable) const
{
    unsigned int frame = TheGameLogic->m_frame;
    if (frame < m_frame1C)
    {
        if (cacheable)
            *cacheable = false;
        return PRE_ATTACK;
    }
    else
    {
        if (frame < m_frame20)
        {
            if (cacheable)
                *cacheable = false;
            return WEAPON_STATUS_5;
        }
        if (m_template->m_flag78 >= 0)
        {
            if (frame < m_frame18 && !m_template->m_ammo.isValid())
                goto return_cached_status;
            if (getRemainingAmmo(false) > 0)
                return READY_TO_FIRE;
            if (frame >= m_frame18)
            {
                WeaponTemplate *weaponTemplate = m_template;
                if (weaponTemplate->m_ammo.isValid())
                {
                    if (isAmmoReady())
                        return READY_TO_FIRE;
                }
            }
            return OUT_OF_AMMO;
        }
        if (frame < m_frame18 && !m_template->m_ammo.isValid())
        return_cached_status:
            return m_status;
        return (WeaponStatus)(getRemainingAmmo(false) <= 0);
    }
}
