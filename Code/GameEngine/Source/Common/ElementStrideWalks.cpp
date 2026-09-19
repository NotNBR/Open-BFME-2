// ModuleInfo::Nugget copy walk, retail 0x00119B50, 45 bytes.
//
// Bounded-by-end-pointer walk handing each 116-byte Nugget slot to stlport
// _STL::_Construct (already matched at 0x00119B30 in ThingFactory.cpp), the
// vector<ModuleInfo::Nugget> uninitialized-copy shape: while (first != last)
// placement-copy into dest, both cursors advancing by sizeof(Nugget)=0x74.
// The Nugget layout (4-byte refcounted name + four 28-byte blocks = 116) is
// the ModuleInfoNuggetCopyCtor TU's proven shape; class ModuleInfo +
// struct Nugget mirrors its spelling so the deduced _Construct specialization
// names the already-matched row.

struct NuggetString
{
	struct Header
	{
		int m_unreconstructed_00;
		unsigned short refCount;
	};
	Header *m_data;
};

struct NuggetBlock
{
	int m_words[7];
};

class ModuleInfo
{
public:
	struct Nugget
	{
		NuggetString name;
		NuggetBlock a;
		NuggetBlock b;
		NuggetBlock c;
		NuggetBlock d;
	};
};

namespace _STL
{
template <class Element, class Value>
void _Construct(Element *slot, const Value &source);
}

ModuleInfo::Nugget *rva00119B50CopyWalk(ModuleInfo::Nugget *first,
	ModuleInfo::Nugget *last, ModuleInfo::Nugget *dest)
{
	ModuleInfo::Nugget *cursor = dest;
	for ( ; first != last; ++first)
	{
		_STL::_Construct(cursor, *first);
		++cursor;
	}
	return cursor;
}
