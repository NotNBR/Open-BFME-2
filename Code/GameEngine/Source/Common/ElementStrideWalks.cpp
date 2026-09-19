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

// 36-byte copy walk, retail 0x00161150, 45 bytes.
//
// Bounded-by-end-pointer walk handing each 36-byte slot to the helper at
// 0x001610F0 (unmatched; pinned here under an address-derived name). Both
// cursors advance by the retail step 0x24; the returned value is the
// advanced dest cursor. Element identity is not recovered -- Elem36 is a
// stride-sized stand-in in the ElementStrideWalks donor's own convention.

struct Elem36
{
	char m_bytes[36];
};

void gen001610F0(Elem36 *slot, const Elem36 *source);

Elem36 *rva00161150CopyWalk(Elem36 *first, Elem36 *last, Elem36 *dest)
{
	Elem36 *cursor = dest;
	for ( ; first != last; ++first)
	{
		gen001610F0(cursor, first);
		++cursor;
	}
	return cursor;
}

// 28-byte copy walk, retail 0x00689750, 45 bytes.
//
// Same shape as the Elem36 walk above: bounded-by-end-pointer walk handing
// each 28-byte slot to the helper at 0x006896F0 (rowed 66-byte pair
// construct body; pinned here under an address-derived name). Both cursors
// advance by the retail step 0x1c; the returned value is the advanced dest
// cursor. Element identity is not recovered -- Elem28 is a stride-sized
// stand-in in the ElementStrideWalks donor's own convention.

struct Elem28
{
	char m_bytes[28];
};

void gen006896F0(Elem28 *slot, const Elem28 *source);

Elem28 *rva00689750CopyWalk(Elem28 *first, Elem28 *last, Elem28 *dest)
{
	Elem28 *cursor = dest;
	for ( ; first != last; ++first)
	{
		gen006896F0(cursor, first);
		++cursor;
	}
	return cursor;
}
