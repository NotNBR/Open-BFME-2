// cl: /O2 /G7 /DNDEBUG /MD /EHsc
//
// FontCharsClass::Blit_Char, retail 0x001588A0 (222 bytes).
// Dedicated TU (render2dsentence.cpp keeps the ZH simple-copy Blit as an
// orphan per the boxrobj precedent; that file has 30 present-unmatched
// markers and must not be disturbed).
//
// Source is the BFME1 FontCharsClass_Blit_Char_BFME.cpp nibble-expansion
// blit (retail carries the same expansion idiom: and 0xfffff000 / shl 4 /
// and 0x0f00 / or / shl 4 / and 0x00f0 / or / shl 4 / and 0x000f / or /
// shl 4, byte-exact). BFME2 adaptations, all retail-measured:
// - Callee is Get_Char_Data @0x00158520 (REL32-decoded; the map lookup at
//   this+0x450, NOT the Thai-first load helper that spacing uses).
// - Record carries an ExtraSpacing word at +4 (same +4 word the spacing
//   record proves): x is biased by it and clamped at zero
//   (movsx + add + jns + xor, retail-measured).
// - Pixel write is an unconditional OR into the dword dest (no
//   PixelOverlap conditional/store like the ZH copy).
// - CharHeight lives at this+0x2C (retail cmp mem).

struct FontCharsClassCharDataStruct
{
	unsigned short Value;
	short Width;
	short ExtraSpacing;
	char m_pad06[2];
	unsigned short *Buffer;
};

class FontCharsClass
{
	const FontCharsClassCharDataStruct *Get_Char_Data(unsigned short ch);
public:
	void Blit_Char(unsigned short ch, unsigned short *dest_ptr, int dest_stride, int x, int y);
private:
	char m_pad00[0x2C];
	int CharHeight;
};

// ?Blit_Char@FontCharsClass@@QAEXGPAGHHH@Z
void FontCharsClass::Blit_Char(unsigned short ch, unsigned short *dest_ptr, int dest_stride, int x, int y)
{
	unsigned int *dest = reinterpret_cast<unsigned int *>(dest_ptr);
	FontCharsClassCharDataStruct const *data = Get_Char_Data(ch);
	if (data != 0 && data->Width != 0) {
		x += data->ExtraSpacing;
		if (x < 0) {
			x = 0;
		}
		int dest_inc = dest_stride >> 2;
		unsigned short *src_ptr = data->Buffer;
		dest += (dest_inc * y) + x;

		for (int row = 0; row < CharHeight; row++) {
			for (int col = 0; col < data->Width; col++) {
				unsigned short pixel = *src_ptr;
				unsigned int curData = pixel;
				curData = (curData & 0xfffff000) << 4;
				curData |= pixel & 0x0f00;
				curData <<= 4;
				curData |= pixel & 0x00f0;
				curData <<= 4;
				curData |= pixel & 0x000f;
				curData <<= 4;
				dest[col] |= curData;
				src_ptr++;
			}
			dest += dest_inc;
		}
	}
}
