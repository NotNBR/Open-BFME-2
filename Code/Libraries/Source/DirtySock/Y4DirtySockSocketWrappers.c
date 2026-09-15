// cl: /Od /GZ /GS /MD /DNDEBUG
/* EA DirtySock socket wrappers, ported verbatim from BFME1
 * Y4DirtySockSocket.c. Retail 0x006699E0 (41B), 0x00669A10 (126B)
 * and 0x0066AB90 (180B).
 *
 * The bind wrapper hands its result to the Winsock error translator,
 * which maps WSAE* failures onto the library's small negative vocabulary.
 * The bounded compare selects unbounded form on negative length; both
 * operands read unsigned, so high-bit differences stay non-negative.
 */

struct Rva007FD4E0Socket
{
	char m_gap[0x16];
	short m_shutdownFlags; /* +0x16 */
	unsigned int m_socket; /* +0x18 */
};

int __stdcall bind(unsigned int socket, const void *address, int addressLength);
int __stdcall WSAGetLastError(void);
int __stdcall shutdown(unsigned int socket, int how);

int Rva007FD540(int result)
{
	if (result < 0)
	{
		result = WSAGetLastError();

		if (result == 10035 || result == 10054)
			result = 0;
		else if (result == 10051 || result == 10065)
			result = -5;
		else if (result == 10057)
			result = -2;
		else if (result == 10061)
			result = -6;
		else
			result = -7;
	}

	return result;
}

int Rva007FD510(struct Rva007FD4E0Socket *socket, const void *address,
	int addressLength)
{
	return Rva007FD540(bind(socket->m_socket, address, addressLength));
}

int Rva007FD4E0(struct Rva007FD4E0Socket *socket, int how)
{
	socket->m_shutdownFlags |= how;
	shutdown(socket->m_socket, how);
	return 0;
}

int Rva007FE6C0(const char *string1, const char *string2, int length)
{
	int difference;
	const unsigned char *first;
	const unsigned char *second;

	first = (const unsigned char *)string1;
	second = (const unsigned char *)string2;
	if (length < 0)
	{
		for (; *first != 0; first++, second++)
		{
			if (*first != *second)
				return *first - *second;
		}
		return 0;
	}
	for (; length > 0; first++, second++, length--)
	{
		difference = *first - *second;
		if (difference != 0)
			return difference;
	}
	return 0;
}
