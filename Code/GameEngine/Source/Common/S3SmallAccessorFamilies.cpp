// A bitfield read and a default-string getter.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/S3SmallAccessorFamilies.cpp); trimmed to the
// two T1 bodies the sweep places.

struct Gen_007f8dc0Bits
{
	char m_bfmeHead[0x20];
	unsigned int m_bfmeFlags;					// +0x20
};

// ?Gen_007f8ee0@@YGHPAUGen_007f8dc0Bits@@@Z
int __stdcall Gen_007f8ee0(Gen_007f8dc0Bits *bits)
{
	return (bits->m_bfmeFlags >> 29) & 1;
}

class Gen_007ea670
{
public:
	char *bfmePlatform(void);

	char m_bfmeHead[0xE1];
	char m_bfmeBuffer[1];						// +0xE1
};

// ?bfmePlatform@Gen_007ea670@@QAEPADXZ
char *Gen_007ea670::bfmePlatform(void)
{
	char *text = m_bfmeBuffer;

	if (*text == 0)
		text = "PC";

	return text;
}
