// cl: /O1 /DNDEBUG /MD
//
// ?isWeaponSlotOnTurret@TurretAI@@QBE_NW4WeaponSlotType@@@Z,
// retail 0x004D81D7, 21 bytes. Dedicated TU.
// Single-mask test: the data at +8 carries the allowed-slot mask at +0x4C;
// the neg/sbb/neg tail is MSVC's bool normalization of the masked test.

typedef bool Bool;

enum WeaponSlotType
{
	WEAPONSLOT_PRIMARY = 0,
	WEAPONSLOT_COUNT = 6
};

struct TurretData
{
	char m_pad[0x4C];
	unsigned m_slotMask;
};

class TurretAI
{
	char m_pad[8];
	TurretData *m_data;

public:
	Bool isWeaponSlotOnTurret(WeaponSlotType wslot) const;
};

// ?isWeaponSlotOnTurret@TurretAI@@QBE_NW4WeaponSlotType@@@Z
Bool TurretAI::isWeaponSlotOnTurret(WeaponSlotType wslot) const
{
	return (m_data->m_slotMask & (1 << wslot)) != 0;
}
