// cl: /O1 /DNDEBUG /MD
//
// 8-byte vector copy loop, retail 0x00254D65, 47 bytes, rowed as ?dup_00254D65
// (single E8 caller at 0x255D0D inside the 0x255CFA forwarder; reached from
// the StructureCollapseUpdateModuleData ctor 0x257A5E via 0x207F0D, among
// others). Element type unproven: the per-element call folds to the same
// bytes as FXBoneInfo::operator= (rowed at 0x1D9990), whose spelling this TU
// reuses for resolution with zero new pins; the dup label claims the bytes
// and asserts no identity. Shape lever: while-loop (not do-while) homes the
// counter late (push esi after the jle), matching retail exactly.

struct FXBoneInfo
{
	int m_a;
	int m_b;
	FXBoneInfo &operator=(const FXBoneInfo &other);
};

FXBoneInfo *copyEightByteRange(FXBoneInfo *first, FXBoneInfo *last, FXBoneInfo *dest)
{
	int count = (int)((char *)last - (char *)first) >> 3;
	while (count > 0) {
		*dest = *first;
		++first;
		++dest;
		--count;
	}
	return dest;
}
