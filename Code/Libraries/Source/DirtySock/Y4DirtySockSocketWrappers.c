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
	struct Rva007FD4E0Socket *m_next; /* +0x00 */
	struct Rva007FD4E0Socket *m_killNext; /* +0x04 */
	int m_family; /* +0x08 */
	int m_type; /* +0x0C */
	int m_protocol; /* +0x10 */
	char m_opened; /* +0x14 */
	char m_reserved15; /* +0x15 */
	short m_shutdownFlags; /* +0x16 */
	unsigned int m_socket; /* +0x18 */
	char m_gap[0x20];
	void *m_callback; /* +0x3C */
	unsigned int m_lastTick; /* +0x40 */
	unsigned int m_rate; /* +0x44 */
	void *m_callbackData; /* +0x48 */
	void (__cdecl *m_callbackProc)(struct Rva007FD4E0Socket *socket,
		int reason, void *data); /* +0x4C */
};

int __stdcall bind(unsigned int socket, const void *address, int addressLength);
int __stdcall WSAGetLastError(void);
int __stdcall shutdown(unsigned int socket, int how);
int __stdcall listen(unsigned int socket, int backlog);

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

int Rva007FD7A0(struct Rva007FD4E0Socket *socket, int backlog)
{
	return Rva007FD540(listen(socket->m_socket, backlog));
}

void *g_Rva0130AB60;
int g_Rva0130AB64;

int Rva007FDEB0(int control, int value, void *pointer)
{
	if (control == 'xmap')
		g_Rva0130AB60 = pointer;
	if (control == 'xdns')
		g_Rva0130AB64 = value;
	return -1;
}

int Rva007FE200(const int *value)
{
	return *value;
}

int Rva007FDE80(struct Rva007FD4E0Socket *socket, void *callback,
	unsigned int rate, void *data,
	void (__cdecl *proc)(struct Rva007FD4E0Socket *, int, void *))
{
	socket->m_rate = rate;
	socket->m_callback = callback;
	socket->m_callbackData = data;
	socket->m_callbackProc = proc;
	return 0;
}

struct Rva0130AB68List
{
	unsigned int m_ownerThread; /* +0x00 */
	unsigned int m_depth; /* +0x04 */
	int m_state; /* +0x08 */
	char m_body[4]; /* +0x0C */
};

extern struct Rva0130AB68List g_Rva0130AB68Default;

void __declspec(dllimport) __stdcall LeaveCriticalSection(void *body);

void Rva007FECB0(struct Rva0130AB68List *list)
{
	struct Rva0130AB68List *node = list ? list : &g_Rva0130AB68Default;

	if (node->m_depth > 1)
	{
		node->m_depth = node->m_depth - 1;
	}
	else
	{
		node->m_ownerThread = 0;
		node->m_depth = 0;
		node->m_state = 0;
		LeaveCriticalSection(node->m_body);
	}
}

unsigned int __declspec(dllimport) __stdcall GetCurrentThreadId(void);
void __declspec(dllimport) __stdcall EnterCriticalSection(void *body);
long __declspec(dllimport) __stdcall InterlockedExchange(long *target, long value);

int Rva007FEB00(struct Rva0130AB68List *list)
{
	struct Rva0130AB68List *node = list ? list : &g_Rva0130AB68Default;

	if (node->m_ownerThread == GetCurrentThreadId())
	{
		node->m_depth = node->m_depth + 1;
		return 1;
	}

	if (InterlockedExchange((long *)&node->m_state, 1))
		return 0;

	EnterCriticalSection(node->m_body);

	node->m_ownerThread = GetCurrentThreadId();
	node->m_depth = node->m_depth + 1;
	return 1;
}

void __declspec(dllimport) __stdcall Sleep(int interval);

void Rva007FEBD0(struct Rva0130AB68List *list)
{
	struct Rva0130AB68List *node = list ? list : &g_Rva0130AB68Default;

	while (!Rva007FEB00(list))
	{
		EnterCriticalSection(node->m_body);

		if (!InterlockedExchange((long *)&node->m_state, 1))
		{
			node->m_ownerThread = GetCurrentThreadId();
			node->m_depth = node->m_depth + 1;
			return;
		}

		LeaveCriticalSection(node->m_body);
		Sleep(1);
	}
}

void __declspec(dllimport) __stdcall DeleteCriticalSection(void *body);
void __declspec(dllimport) __stdcall InitializeCriticalSection(void *body);

void Rva007FEAA0(struct Rva0130AB68List *list)
{
	struct Rva0130AB68List *node = list ? list : &g_Rva0130AB68Default;

	node->m_state = 0;
	DeleteCriticalSection(node->m_body);
}

void Rva007FEA20(struct Rva0130AB68List *list)
{
	struct Rva0130AB68List *node = list ? list : &g_Rva0130AB68Default;

	node->m_ownerThread = 0;
	node->m_depth = 0;
	node->m_state = 0;
	InitializeCriticalSection(node->m_body);
}

extern int g_Rva0130AC90;

void Rva007FEE10(void)
{
	Rva007FEBD0(&g_Rva0130AC90);
	Rva007FECB0(&g_Rva0130AC90);
}

extern void *g_Rva0130AB58Head;
extern struct Rva007FD4E0Socket *g_Rva0130AB5CKillList;
extern char g_Rva012C3C88Format[];
int Rva007FE780(const char *format, ...);
int __stdcall closesocket(unsigned int socket);

int Rva007FD3F0(struct Rva007FD4E0Socket *socket)
{
	struct Rva007FD4E0Socket **link;
	unsigned char found;

	found = 0;
	Rva007FEBD0(0);
	for (link = (struct Rva007FD4E0Socket **)&g_Rva0130AB58Head;
		*link != 0;
		link = &(*link)->m_next)
	{
		if (*link == socket)
		{
			*link = socket->m_next;
			found = 1;
			break;
		}
	}
	Rva007FECB0(0);

	if (!found)
	{
		Rva007FE780(g_Rva012C3C88Format, socket);
		return -1;
	}

	Rva007FEE10();

	if (socket->m_socket >= 0)
	{
		shutdown(socket->m_socket, 2);
		closesocket(socket->m_socket);
	}
	socket->m_socket = 0xFFFFFFFF;
	socket->m_opened = 0;

	Rva007FEBD0(0);
	socket->m_killNext = g_Rva0130AB5CKillList;
	g_Rva0130AB5CKillList = socket;
	Rva007FECB0(0);
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

struct Rva007FD920IpHeader
{
	unsigned char m_versionAndLength; /* +0x00, low nibble is IHL */
	unsigned char m_skip[7];
	unsigned char m_timeToLive; /* +0x08 */
};

int __stdcall setsockopt(unsigned int socket, int level, int option,
	const void *value, int valueLength);
int __stdcall send(unsigned int socket, const char *buffer, int length,
	int flags);
int __stdcall sendto(unsigned int socket, const char *buffer, int length,
	int flags, const void *to, int toLength);
void *Rva007FD660(char *temp, void *address);

int Rva007FD920(struct Rva007FD4E0Socket *socket, const char *buffer,
	int length, int flags, void *to, int toLength)
{
	int result;
	char scratch[0x10];
	const struct Rva007FD920IpHeader *header;
	int timeToLive;

	if (socket->m_type == 3)
	{
		header = (const struct Rva007FD920IpHeader *)buffer;
		timeToLive = header->m_timeToLive;
		setsockopt(socket->m_socket, 0, 4, &timeToLive, 4);

		length -= (header->m_versionAndLength & 0x0F) * 4;
		buffer = buffer + (header->m_versionAndLength & 0x0F) * 4;
		if (length < 0)
			length = 0;
	}

	if (to == 0)
		result = send(socket->m_socket, buffer, length, 0);
	else
		result = sendto(socket->m_socket, buffer, length, 0,
			Rva007FD660(scratch, to), toLength);

	return Rva007FD540(result);
}

int __stdcall recv(unsigned int socket, char *buffer, int length, int flags);
int __stdcall recvfrom(unsigned int socket, char *buffer, int length,
	int flags, char *from, int *fromLength);
unsigned int __declspec(dllimport) __stdcall GetTickCount(void);

unsigned int Rva007FEA00(void)
{
	return GetTickCount();
}

long __cdecl time(long *timer);

unsigned int Rva007FEF60(void)
{
	return time(0);
}

int Rva007FDA50(struct Rva007FD4E0Socket *socket, char *buffer, int length,
	int flags, char *from, int *fromLength)
{
	int result;
	unsigned int tick;
	int translated;

	if (from == 0)
	{
		result = recv(socket->m_socket, buffer, length, 0);
	}
	else
	{
		result = recvfrom(socket->m_socket, buffer, length, 0, from,
			fromLength);
		if (result > 0)
		{
			tick = Rva007FEA00();
			from[11] = (char)tick; tick >>= 8;
			from[10] = (char)tick; tick >>= 8;
			from[9] = (char)tick; tick >>= 8;
			from[8] = (char)tick;
		}
	}

	if (result == 0)
		translated = -1;
	else
		translated = Rva007FD540(result);
	result = translated;

	if (flags & 0x20)
	{
		if (result == -1)
			result = 0;
		else if (result == 0)
			result = -1;
	}
	return result;
}

int __stdcall connect(unsigned int socket, const void *address,
	int addressLength);

int Rva007FD5C0(struct Rva007FD4E0Socket *socket, const void *address,
	int addressLength)
{
	char temp[0x10];

	socket->m_opened = 0;
	return Rva007FD540(connect(socket->m_socket,
		Rva007FD660(temp, (void *)address), addressLength));
}

unsigned int __stdcall socket(int family, int type, int protocol);
int __stdcall ioctlsocket(unsigned int socket, long command,
	unsigned long *argument);
void *Rva007F0000(int size);
void *__cdecl memset(void *destination, int value, unsigned int count);

struct Rva007FD4E0Socket *Rva007FD2D0(int family, int type, int protocol)
{
	unsigned int handle;
	struct Rva007FD4E0Socket *socketObject;
	unsigned long nonblock = 1;

	handle = socket(family, type, protocol);
	if (handle == 0xFFFFFFFF)
		return 0;

	socketObject = (struct Rva007FD4E0Socket *)Rva007F0000(0x50);
	memset(socketObject, 0, 0x50);
	socketObject->m_socket = handle;

	ioctlsocket(handle, 0x8004667E, &nonblock);
	if (type == 2)
		setsockopt(handle, 0xFFFF, 0x20, &nonblock, 4);

	socketObject->m_family = family;
	socketObject->m_type = type;
	socketObject->m_protocol = protocol;

	Rva007FEBD0(0);
	socketObject->m_next = (struct Rva007FD4E0Socket *)g_Rva0130AB58Head;
	g_Rva0130AB58Head = socketObject;
	Rva007FECB0(0);

	return socketObject;
}

unsigned int __stdcall accept(unsigned int socket, void *address,
	unsigned int *addressLength);

struct Rva007FD4E0Socket *Rva007FD7D0(struct Rva007FD4E0Socket *listenSocket,
	void *address, unsigned int *addressLength)
{
	struct Rva007FD4E0Socket *acceptedSocket;
	unsigned int clientHandle;
	unsigned long nonblock;

	acceptedSocket = 0;
	nonblock = 1;

	if (listenSocket->m_socket == 0xFFFFFFFF)
		return 0;

	if (address != 0 && *addressLength < 0x10)
		return 0;

	if (listenSocket->m_family == 2)
	{
		clientHandle = accept(listenSocket->m_socket, address, addressLength);
		if (clientHandle != 0xFFFFFFFF)
		{
			ioctlsocket(clientHandle, 0x8004667E, &nonblock);

			acceptedSocket = (struct Rva007FD4E0Socket *)Rva007F0000(0x50);
			memset(acceptedSocket, 0, 0x50);
			acceptedSocket->m_socket = clientHandle;
			acceptedSocket->m_family = listenSocket->m_family;
			acceptedSocket->m_type = listenSocket->m_type;
			acceptedSocket->m_protocol = listenSocket->m_protocol;
			acceptedSocket->m_opened = 1;

			Rva007FEBD0(0);
			acceptedSocket->m_next = (struct Rva007FD4E0Socket *)g_Rva0130AB58Head;
			g_Rva0130AB58Head = acceptedSocket;
			Rva007FECB0(0);
		}
	}

	return acceptedSocket;
}

extern int g_Rva0130AB54Version;

void *__cdecl memcpy(void *destination, const void *source,
	unsigned int count);
int __stdcall getsockname(unsigned int socket, void *name, int *nameLength);
int __stdcall WSAIoctl(unsigned int socket, unsigned int code,
	const void *inBuffer, int inLength, void *outBuffer, int outLength,
	int *bytesReturned, void *overlapped, void *completion);

#define SOCKET_ADDR_BYTES( p ) \
	( ( ( ( ( (const unsigned char *)( p ) )[ 4 ] << 8 ) \
	| ( (const unsigned char *)( p ) )[ 5 ] ) << 8 \
	| ( (const unsigned char *)( p ) )[ 6 ] ) << 8 \
	| ( (const unsigned char *)( p ) )[ 7 ] )

int Rva007FE310(void *dest, int destLength, const void *src, int srcLength)
{
	unsigned int probeSocket;
	char queryBuffer[0x10];
	int lastError;

	if (destLength != srcLength)
		return -1;

	if (*(const unsigned short *)src == 2)
	{
		memcpy(dest, src, destLength);
		((unsigned char *)dest)[7] = 0;
		((unsigned char *)dest)[6] = 0;
		((unsigned char *)dest)[5] = 0;
		((unsigned char *)dest)[4] = 0;

		probeSocket = socket(2, 2, 0);
		if (probeSocket != 0xFFFFFFFF)
		{
			if (g_Rva0130AB54Version >= 0x200)
			{
				if (WSAIoctl(probeSocket, 0xC8000014, src, srcLength, queryBuffer,
					0x10, &destLength, 0, 0) < 0)
				{
					lastError = WSAGetLastError();
				}
				memcpy((char *)dest + 4, queryBuffer + 4, 4);

				if (SOCKET_ADDR_BYTES(dest) == 0x7F000001)
					memcpy((char *)dest + 4, (const char *)src + 4, 4);
			}

			if (SOCKET_ADDR_BYTES(dest) == 0
				&& connect(probeSocket, src, srcLength) == 0
				&& getsockname(probeSocket, queryBuffer, &destLength) == 0)
			{
				memcpy((char *)dest + 4, queryBuffer + 4, 4);
			}

			closesocket(probeSocket);
		}
		return 0;
	}

	memset(dest, 0, destLength);
	return -3;
}

struct SocketFdSet
{
	unsigned int fd_count;
	unsigned int fd_array[64];
};

struct SocketTimeVal
{
	long tv_sec;
	long tv_usec;
};

#define SOCKET_FD_SET(handle, set) \
	do { \
		unsigned int slotIndex; \
		for (slotIndex = 0; slotIndex < (set)->fd_count; slotIndex++) \
		{ \
			if ((set)->fd_array[slotIndex] == (handle)) \
				break; \
		} \
		if (slotIndex == (set)->fd_count) \
		{ \
			if ((set)->fd_count < 64) \
			{ \
				(set)->fd_array[slotIndex] = (handle); \
				(set)->fd_count++; \
			} \
		} \
	} while (0)

int __stdcall select(int nfds, struct SocketFdSet *readfds,
	struct SocketFdSet *writefds, struct SocketFdSet *exceptfds,
	const struct SocketTimeVal *timeout);
int __stdcall getpeername(unsigned int socket, void *name, int *nameLength);

int Rva007FDB60(struct Rva007FD4E0Socket *socket, int selector, void *buffer,
	int bufferLength)
{
	int queryResult;
	struct SocketFdSet writableSet;
	struct SocketFdSet exceptSet;
	struct SocketTimeVal timeout;
	char peerAddress[0x10];

	if (buffer != 0)
		memset(buffer, 0, bufferLength);

	if (socket->m_socket == 0xFFFFFFFF)
		return -7;

	if (selector == 'conn')
	{
		getpeername(socket->m_socket, buffer, &bufferLength);
		return 0;
	}

	if (selector == 'bind')
	{
		getsockname(socket->m_socket, buffer, &bufferLength);
		return 0;
	}

	if (selector == 'peer')
	{
		getpeername(socket->m_socket, buffer, &bufferLength);
		return 0;
	}

	if (selector == 'stat')
	{
		if (socket->m_opened == 0)
		{
			writableSet.fd_count = 0;
			exceptSet.fd_count = 0;
			SOCKET_FD_SET(socket->m_socket, &writableSet);
			SOCKET_FD_SET(socket->m_socket, &exceptSet);

			timeout.tv_sec = timeout.tv_usec = 0;

			if (select(1, 0, &writableSet, &exceptSet, &timeout) != 0)
			{
				if (exceptSet.fd_count > 0)
					socket->m_opened = -1;
				if (writableSet.fd_count > 0)
					socket->m_opened = 1;
			}
		}

		if (socket->m_opened > 0)
		{
			bufferLength = 0x10;
			queryResult = Rva007FD540(getpeername(socket->m_socket, peerAddress,
				&bufferLength));
			if (queryResult == -2)
				socket->m_opened = -1;
		}

		return socket->m_opened > 0;
	}

	return -1;
}

struct IdleCallbackEntry
{
	void *callbackFunction;
	void *callbackRef;
};

struct IdleCallbackEntry g_Rva0130AB90[64];
int g_Rva0130ACB4;

void Rva007FED40(void *callback, void *ref)
{
	if (callback == 0 || ref == 0)
		return;
	g_Rva0130AB90[g_Rva0130ACB4].callbackFunction = callback;
	g_Rva0130AB90[g_Rva0130ACB4].callbackRef = ref;
	g_Rva0130ACB4++;
}

void Rva007FED90(void *callback, void *ref)
{
	int slotIndex;

	if (callback == 0 || ref == 0)
		return;
	for (slotIndex = 0; slotIndex < g_Rva0130ACB4; slotIndex++)
	{
		if (g_Rva0130AB90[slotIndex].callbackFunction == callback &&
			g_Rva0130AB90[slotIndex].callbackRef == ref)
		{
			g_Rva0130AB90[slotIndex].callbackFunction = 0;
			g_Rva0130AB90[slotIndex].callbackRef = 0;
			break;
		}
	}
}

void Rva007FEE40(void)
{
	int tableIndex;
	void (__cdecl *idleCallback)(void *ref);
	void *callbackRef;

	if (Rva007FEB00(&g_Rva0130AC90) != 0)
	{
		for (tableIndex = 0; tableIndex < g_Rva0130ACB4; tableIndex++)
		{
			idleCallback = (void (__cdecl *)(void *))
				g_Rva0130AB90[tableIndex].callbackFunction;
			callbackRef = g_Rva0130AB90[tableIndex].callbackRef;

			if (idleCallback == 0 || callbackRef == 0)
			{
				g_Rva0130AB90[tableIndex].callbackFunction =
					g_Rva0130AB90[g_Rva0130ACB4 - 1].callbackFunction;
				g_Rva0130AB90[tableIndex].callbackRef =
					g_Rva0130AB90[g_Rva0130ACB4 - 1].callbackRef;
				g_Rva0130AB90[g_Rva0130ACB4 - 1].callbackFunction = 0;
				g_Rva0130AB90[g_Rva0130ACB4 - 1].callbackRef = 0;
				g_Rva0130ACB4 = g_Rva0130ACB4 - 1;
				tableIndex = tableIndex - 1;
				continue;
			}

			idleCallback(callbackRef);
		}

		Rva007FECB0(&g_Rva0130AC90);
	}
}

extern int g_Rva012C3CDCDraining;
extern int g_Rva0130ACB8Thread;

void Rva007FE620(void)
{
	g_Rva012C3CDCDraining = 1;

	while (g_Rva0130ACB8Thread != 0)
	{
		Rva007FEE40();
		Sleep(0x32);
	}

	g_Rva012C3CDCDraining = 0;
}

void Rva007FE670(void)
{
	g_Rva0130ACB8Thread = 0;

	while (g_Rva012C3CDCDraining > 0)
		Sleep(1);

	Rva007FEAA0(0);
	Rva007FEAA0((struct Rva0130AB68List *)&g_Rva0130AC90);
}
