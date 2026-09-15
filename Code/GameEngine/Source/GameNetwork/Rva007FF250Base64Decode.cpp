// cl: /O2 /MD
// EA FESL Base64 decoder, ported verbatim from BFME1
// Rva007FF250Base64Decode.cpp. Retail 0x0066B720 (402B).

extern const char g_Base64ReverseTable[];

int rva007FF250Decode(int length, const char *source, unsigned char *destination)
{
	int outputOffset = 0;
	if (length % 4 != 0)
		return 0;
	if (length != 0)
	{
		source++;
		do
		{
			char code0 = source[-1];
			char code1 = source[0];
			char code2 = source[1];
			char code3 = source[2];
			if (code0 < '+' || code1 < '+' || code2 < '+' || code3 < '+')
				return 0;
			if (code0 > 'z' || code1 > 'z' || code2 > 'z' || code3 > 'z')
				return 0;

			code0 = g_Base64ReverseTable[code0];
			code1 = g_Base64ReverseTable[code1];
			code2 = g_Base64ReverseTable[code2];
			code3 = g_Base64ReverseTable[code3];
			length -= 4;
			if (code0 < 0 || code1 < 0)
				return 0;
			if (code2 < 0 || code3 < 0)
			{
				if (source[1] == '=')
				{
					if (source[2] == '=')
					{
						destination[outputOffset] =
							(unsigned char)((code0 << 2) | ((code1 >> 4) & 3));
						return length == 0;
					}
				}
				if (code2 >= 0 && source[2] == '=')
				{
					destination[outputOffset] =
						(unsigned char)((code0 << 2) | ((code1 >> 4) & 3));
					destination[outputOffset + 1] =
						(unsigned char)((code1 << 4) | ((code2 >> 2) & 0x3f));
					return length == 0;
				}
			}
			else
			{
				destination[outputOffset] =
					(unsigned char)((code0 << 2) | ((code1 >> 4) & 3));
				destination[outputOffset + 1] =
					(unsigned char)((code1 << 4) | ((code2 >> 2) & 0x3f));
				destination[outputOffset + 2] =
					(unsigned char)((code2 << 6) | code3);
				outputOffset += 3;
				source += 4;
			}
		} while (length != 0);
	}
	return 1;
}
