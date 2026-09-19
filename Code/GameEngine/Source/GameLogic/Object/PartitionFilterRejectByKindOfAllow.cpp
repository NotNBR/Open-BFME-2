// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// BFME2 PartitionFilterRejectByKindOf::allow, retail RVA 0x0026115D (25B).
// Dedicated TU: the shared PartitionManager.cpp TU sees 16-byte KindOf masks
// (offsets +0x4/+0x14), but retail reads Set at +0x8 and Clear at +0x24 and the
// isKindOfMulti core at 0x30A142 loops 7 dwords, so BFME2 masks are 28 bytes.
// The BFME1 sibling (PartitionFilterRejectByKindOf.cpp) uses the same
// this-relative cast idiom with ITS offsets (+0x08/+0x20); the offsets here
// are BFME2 retail immediates. Callees resolve by name (isKindOfMulti pin).

typedef bool Bool;

template<int NUM_BITS>
class BitFlags
{
public:
	// Retail-measured: 7 words (isKindOfMulti core compares 7 dwords).
	// The template argument keeps the ?$BitFlags@$0HE mangling.
	unsigned int m_words[7];
};

class Thing
{
public:
	Bool isKindOfMulti(const BitFlags<116> &mustBeSet, const BitFlags<116> &mustBeClear) const;
};

class Object : public Thing
{
};

class PartitionFilterRejectByKindOf
{
public:
	virtual Bool allow(Object *objOther);
};

Bool PartitionFilterRejectByKindOf::allow(Object *objOther)
{
	const BitFlags<116> &mustBeSet = *(const BitFlags<116> *)((const char *)this + 0x08);
	const BitFlags<116> &mustBeClear = *(const BitFlags<116> *)((const char *)this + 0x24);
	return !objOther->isKindOfMulti(mustBeSet, mustBeClear);
}
