// cl: /O1
//
// vector<ModuleInfo::Nugget>::erase, retail 0x0033C3BC, 55 bytes.
//
// Single-element erase over the 20-byte ModuleInfo::Nugget (two AsciiStrings,
// a ModuleData pointer, an Int and three Bools): shift the tail down with the
// out-of-line four-argument _STL::__copy_ptrs (by-reference __false_type tag,
// pinned at 0x002CF2B8), pop the finish pointer and destroy the vacated slot
// with the out-of-line Nugget dtor (pinned at 0x002CF51B). Identity is proven
// by the landed caller ModuleInfo::clearAiModuleInfo at 0x0033C882, which
// walks m_info with a 0x14 stride and tail-calls this body.

class AsciiString
{
public:
	~AsciiString();

private:
	char *m_data;
};

class ModuleData
{
};

class ModuleInfo
{
public:
	struct Nugget
	{
		~Nugget();

		AsciiString m_first;
		AsciiString m_moduleTag;
		const ModuleData *m_data;
		int m_interfaceMask;
		unsigned char m_copiedFromDefault;
		unsigned char m_inheritable;
		unsigned char m_overrideableByLikeKind;
		unsigned char m_pad;
	};
};

namespace _STL
{

struct __false_type
{
	__false_type()
	{
	}
};

template <class Type>
class allocator
{
};

template <class Type, class Allocator>
class vector
{
public:
	typedef Type *iterator;

	iterator erase(iterator position);
	iterator end() { return m_finish; }

private:
	iterator m_start;
	iterator m_finish;
	iterator m_endOfStorage;
};

template <class InputIter, class OutputIter>
OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result,
	const __false_type &tag);

}

_STL::vector<ModuleInfo::Nugget, _STL::allocator<ModuleInfo::Nugget> >::iterator
_STL::vector<ModuleInfo::Nugget, _STL::allocator<ModuleInfo::Nugget> >::erase(
	iterator position)
{
	if (position + 1 != end())
	{
		__copy_ptrs(position + 1, m_finish, position, __false_type());
	}

	--m_finish;
	m_finish->~Nugget();
	return position;
}
