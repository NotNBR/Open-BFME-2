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

void Rva007FEBD0(struct Rva0130AB68List *list);
void Rva007FECB0(struct Rva0130AB68List *list);

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
