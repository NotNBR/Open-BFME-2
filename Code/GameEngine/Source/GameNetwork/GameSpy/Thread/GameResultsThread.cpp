// cl: /DNDEBUG /MD /EHsc

// Open-BFME: _STL::_Deque_iterator_base<GameResultsRequest>::_M_set_node,
// retail 0x00419D9C, 21 bytes. BFME1 donor is
// Code/GameEngine/Source/GameNetwork/GameSpy/Thread/GameResultsThread.cpp
// (b1 0x0063FFE0); the body is STLport's deque iterator re-seat, identical
// in both games once relocations are masked.
//
// GameResultsRequest is two strings around a port (hostname, port, results),
// 28 bytes under STLport, and STLport sizes deque blocks at 128 bytes
// (_MAX_BYTES), so each node holds 128 / 28 = 4 requests. Re-seating the
// iterator stores the new map node, reloads the block start from it, and
// parks the block end 4 elements (0x70 bytes) past the start.

class GameResultsRequest
{
	char m_requestBody[0x1C];
};

namespace _STL
{

template <class T>
struct _Deque_iterator_base
{
	typedef T value_type;
	typedef int difference_type;
	typedef T **_Map_pointer;

	enum { _blocksize = 128, __buffer_size = sizeof(T) < 128 ? 128 / sizeof(T) : 1 };

	void _M_set_node(_Map_pointer newNode);

	T *_M_cur;				// +0x00
	T *_M_first;			// +0x04
	T *_M_last;				// +0x08
	_Map_pointer _M_node;		// +0x0C
};

template <class T>
void _Deque_iterator_base<T>::_M_set_node(_Map_pointer newNode)
{
	_M_last = (_M_first = *(_M_node = newNode)) + difference_type(__buffer_size);
}

template void _Deque_iterator_base<GameResultsRequest>::_M_set_node(GameResultsRequest **);

}
