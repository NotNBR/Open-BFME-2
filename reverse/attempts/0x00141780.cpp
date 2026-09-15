// ??1BfmeNonRefSceneList@@UAE@XZ
// partial score=0.9 date=2026-09-15
// cl: /DNDEBUG /MD /EHsc /O2 /Ob2
// ??1BfmeNonRefSceneList@@UAE@XZ
//
// BfmeNonRefSceneList destructor at 0x00141780 (96 bytes): drains the
// list through the inherited GenericMultiListClass remover, then runs
// the trivial base destructor.  Lives in its own unit (like the other
// one-body scene TUs) to avoid disturbing its sibling unit.

class MultiListObjectClass
{
public:
    virtual ~MultiListObjectClass();
};

class GenericMultiListClass
{
public:
    virtual ~GenericMultiListClass();

protected:
    class MultiListObjectClass *Internal_Remove_List_Head(void);

private:
    // No data members: derived lists keep their head at +0x04.
};

struct BfmeSceneListNode
{
    void *prev;
    void *next;
    void *next_list;
    void *object_link;
    void *list;
};

class BfmeNonRefSceneList : public GenericMultiListClass
{
public:
    virtual ~BfmeNonRefSceneList();
    BfmeSceneListNode head;
};

// ??1BfmeNonRefSceneList@@UAE@XZ
BfmeNonRefSceneList::~BfmeNonRefSceneList()
{
    BfmeSceneListNode &sentinel = head;
    while (&sentinel != head.next) {
        Internal_Remove_List_Head();
    }
}
