// cl: /Od /GZ /GS /MD /DNDEBUG
/* EA DirtySock socket wrappers, ported verbatim from BFME1
 * Y4DirtySockSocket.c. Retail 0x006699E0 (41B) and 0x00669A10 (126B).
 *
 * The bind wrapper hands its result to the Winsock error translator,
 * which maps WSAE* failures onto the library's small negative vocabulary.
 */

struct Rva007FD4E0Socket
{
	char m_gap[0x18];
	unsigned int m_socket; /* +0x18 */
};

int __stdcall bind(unsigned int socket, const void *address, int addressLength);
int __stdcall WSAGetLastError(void);

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
