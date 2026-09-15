// cl: /Od /GZ /GS /MD /DNDEBUG
/* EA DirtySock -- host:port text parser plus socket-address compare, ported
 * verbatim from BFME1 Y4DirtySockAddrText.c. Retail 0x0066C2A0 (442B),
 * 0x0066BBF0 (108B) and 0x0066C180 (238B).
 *
 * Parses "host:port" with an optional third colon-separated number.
 * Returns a bitmask of what was found: bit 0 for non-zero address,
 * bit 1 for port field, bit 2 for third field. The builder zeroes a
 * 16-byte socket address, runs the parser, and writes address and port
 * back big-endian.
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

struct Rva007FFCB0Addr
{
	unsigned short m_family; /* +0x00 */
	unsigned short m_port; /* +0x02 */
	unsigned int m_address; /* +0x04 */
	unsigned int m_reserved8; /* +0x08 */
	unsigned int m_reservedC; /* +0x0C */
};

int Rva007FFCB0(struct Rva007FFCB0Addr *sa, const char *text)
{
	int iResult;
	int iPort;
	unsigned int uAddr;
	unsigned int uTemp;

	iResult = 0;

	sa->m_family = 2;
	sa->m_port = 0;
	sa->m_address = 0;
	sa->m_reserved8 = 0;
	sa->m_reservedC = 0;

	iResult = Rva007FFDD0(&uAddr, &iPort, 0, text);

	uTemp = uAddr;
	((unsigned char *)sa)[7] = (unsigned char)uTemp; uTemp >>= 8;
	((unsigned char *)sa)[6] = (unsigned char)uTemp; uTemp >>= 8;
	((unsigned char *)sa)[5] = (unsigned char)uTemp; uTemp >>= 8;
	((unsigned char *)sa)[4] = (unsigned char)uTemp;

	((unsigned char *)sa)[2] = (unsigned char)(iPort >> 8);
	((unsigned char *)sa)[3] = (unsigned char)iPort;

	return iResult;
}
