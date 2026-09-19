// cl: /DNDEBUG /MD /EHsc /Og-

// bfmeSmallFreePM, retail 0x00027A40 (75B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/BfmeTwoHundredSeventyThree.cpp
// (BFME1 0x0082E4F0). Only the placed small-block arm is defined here; the
// donor's bfmeFreePM size dispatch stays out, so the unmatched-definition
// gate passes. The /Og- mode is load-bearing: it retains the false-thread
// specialization's constant lock tests, which is what emits retail's
// acquire/release call pair around the free-list push.

namespace _STL
{

class NodeAllocMutex
{
public:
	void _M_acquire_lock(void);
	void _M_release_lock(void);
};

template <bool __threads, int __inst>
class _Node_Alloc_Lock
{
	int m_dummy;
	int m_dummy2;

public:
	_Node_Alloc_Lock()
	{
		if (__threads)
			_S_lock._M_acquire_lock();
	}
	~_Node_Alloc_Lock()
	{
		if (__threads)
			_S_lock._M_release_lock();
	}

	static NodeAllocMutex _S_lock;
};

template <bool __threads, int __inst>
NodeAllocMutex _Node_Alloc_Lock<__threads, __inst>::_S_lock;

}

struct BfmeFreeListNode
{
	BfmeFreeListNode *m_next;
};

extern BfmeFreeListNode *bfmeFreeList[0x10];

// ?bfmeSmallFreePM@@YAXPAXI@Z, retail 0x00027A40 (75B).
void bfmeSmallFreePM(void *at, unsigned int bytes)
{
	BfmeFreeListNode * volatile *my_free_list =
		bfmeFreeList + ((bytes - 1) >> 3);
	_STL::_Node_Alloc_Lock<false, 0> lock_instance;
	((BfmeFreeListNode *)at)->m_next = *my_free_list;
	*my_free_list = (BfmeFreeListNode *)at;
}
