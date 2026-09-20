// cl: /DNDEBUG /MD /EHsc /O1
// SmudgeSet::reset at retail 0x002D269B (35B).
//
// Dedicated TU. BFME1 donor
// (reference/open-bfme-1/Code/GameEngine/Source/GameClient/System/Smudge.cpp,
// SmudgeSet::reset) verbatim: Head loop over the used list at +0x10 (head
// at +0x14), Remove_Head, Add_Head to the static free list at retail
// 0x00DBCBF4 (sacrificial definition here; DIR32 auto-patches).
// Calls resolve to the DLList<Smudge> Remove_Head pin at 0x002D2613 and
// the DLList<Smudge> Add_Head pin at 0x002D25E2.

typedef int Int;
typedef int Bool;

class W3DMPO {};

template <class T> class DLNodeClass;

template <class T>
class DLListClass
{
	friend DLNodeClass<T>;
	DLNodeClass<T> *head;
	DLNodeClass<T> *tail;

public:
	DLListClass() : head(0), tail(0) {}
	virtual ~DLListClass() { }

	void Add_Head(DLNodeClass<T> *node);
	void Add_Tail(DLNodeClass<T> *node);
	void Remove_Head();

	T *Head() { return static_cast<T *>(head); }
};

template <class T>
class DLNodeClass : public W3DMPO
{
	friend DLListClass<T>;
	DLNodeClass<T> *succ;
	DLNodeClass<T> *pred;
	DLListClass<T> *list;
public:
	DLNodeClass() : succ(0), pred(0), list(0) {}
	~DLNodeClass() { Remove(); }

	void Remove();
};

struct Smudge : public DLNodeClass<Smudge>
{
};

struct SmudgeSet : public DLNodeClass<SmudgeSet>
{
public:
	SmudgeSet(void);
	virtual ~SmudgeSet();
	void reset(void);

private:
	DLListClass<Smudge> m_usedSmudgeList;
	static DLListClass<Smudge> m_freeSmudgeList;
	Int m_usedSmudgeCount;
};

DLListClass<Smudge> SmudgeSet::m_freeSmudgeList;

// ?reset@SmudgeSet@@QAEXXZ
void SmudgeSet::reset(void)
{
	Smudge *head;

	while ((head = m_usedSmudgeList.Head()) != 0) {
		m_usedSmudgeList.Remove_Head();
		m_freeSmudgeList.Add_Head(head);	//add to free list
	}
}
