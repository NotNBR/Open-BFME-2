// cl: /Od /GZ /GS /MD /DNDEBUG
/* EA DirtySock -- host:port text parser plus socket-address compare, ported
 * verbatim from BFME1 Y4DirtySockAddrText.c. Retail 0x0066C2A0 (442B)
 * and 0x0066BBF0 (108B).
 *
 * Parses "host:port" with an optional third colon-separated number.
 * Returns a bitmask of what was found: bit 0 for non-zero address,
 * bit 1 for port field, bit 2 for third field.
 */

int Rva007FFDD0(unsigned int *address, int *port, int *extra,
	const char *text)
{
	int iFlags;
	int iValue;

	iFlags = 0;

	while (*text > 0 && *text <= ' ')
		text++;

	for (iValue = 0;
		(*text >= '0' && *text <= '9') || *text == '.';
		text++)
	{
		if (*text != '.')
		{
			iValue = (iValue - (iValue & 0xFF))
				+ (iValue & 0xFF) * 10 + (*text & 0x0F);
		}
		else
		{
			iValue = iValue << 8;
		}
	}

	*address = iValue;
	if (iValue != 0)
		iFlags |= 1;

	while (*text != ':' && *text != 0)
		text++;

	iValue = 0;
	if (*text == ':')
	{
		text++;
		for (; *text >= '0' && *text <= '9'; text++)
			iValue = iValue * 10 + (*text & 0x0F);
		iFlags |= 2;
	}
	*port = iValue;

	if (extra != 0)
	{
		iValue = 0;
		if (*text == ':')
		{
			text++;
			for (; *text >= '0' && *text <= '9'; text++)
				iValue = iValue * 10 + (*text & 0x0F);
			iFlags |= 4;
		}
		*extra = iValue;
	}

	return iFlags;
}

struct Rva007FF720SockAddr
{
	unsigned short m_family; /* +0x00 */
	char m_data[14]; /* +0x02 */
};

int Rva007FE6C0(const char *string1, const char *string2, int length);

int Rva007FF720(const struct Rva007FF720SockAddr *first,
	const struct Rva007FF720SockAddr *second)
{
	int compareLength;

	compareLength = 14;

	if (first->m_family != second->m_family)
		return first->m_family - second->m_family;

	if (first->m_family == 2)
		compareLength = 6;

	return Rva007FE6C0(first->m_data, second->m_data, compareLength);
}
