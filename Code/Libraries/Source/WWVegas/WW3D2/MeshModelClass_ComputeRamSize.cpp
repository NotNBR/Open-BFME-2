// Open-BFME: MeshModelClass::Compute_Ram_Size at retail RVA 0x0096C9B0.
// BFME2 repair: geometry base is 0x8C (retail reads +0x8C/+0x90/+0x98),
// 8 less than BFME1's 0x94; tail layout otherwise identical.

class MeshGeometryClass
{
	char m_base[0x8C];

public:
	int Compute_Ram_Size();
};

class MeshMatDescClass
{
public:
	int Compute_Ram_Size();
};

class BfmeThingVNQ
{
public:
	int bfmeTotalVNQ();
};

class MeshModelClass : public MeshGeometryClass
{
	MeshMatDescClass *DefMatDesc;
	MeshMatDescClass *AlternateMatDesc;
	MeshMatDescClass *CurMatDesc;
	BfmeThingVNQ *MatInfo;

public:
	int Compute_Ram_Size();
};

int MeshModelClass::Compute_Ram_Size()
{
	int size = MeshGeometryClass::Compute_Ram_Size();
	if (DefMatDesc != 0)
		size += DefMatDesc->Compute_Ram_Size();
	if (AlternateMatDesc != 0)
		size += AlternateMatDesc->Compute_Ram_Size();
	if (MatInfo != 0)
		size += MatInfo->bfmeTotalVNQ();
	return size;
}
