// cl: /O1 /DNDEBUG /MD
//
// ?GameGetColorComponents@@YAXHPAE000@Z, retail 0x002D2A9F, 43 bytes.
//
// Direct port of the Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/Common/System/color_ops.cpp,
// matched 44 bytes there): unpack an int color into its alpha/red/green/blue
// bytes. BFME2 retail is one byte shorter; the channel-unpack head
// (shr 0x18, sar 0x10) matches the reference shape.

typedef int Color;
typedef unsigned char UnsignedByte;

// ?GameGetColorComponents@@YAXHPAE000@Z
void GameGetColorComponents(Color color, UnsignedByte *red, UnsignedByte *green, UnsignedByte *blue, UnsignedByte *alpha)
{
	*alpha = (color & 0xFF000000) >> 24;
	*red = (color & 0x00FF0000) >> 16;
	*green = (color & 0x0000FF00) >> 8;
	*blue = (color & 0x000000FF);
}
