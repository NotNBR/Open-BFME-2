// cl: /O1 /DNDEBUG /MD /EHsc
//
// ??1CreateCrateDieModuleData@@UAE@XZ @0x35CCCA (89 bytes): CreateCrateDie
// module-data destructor. Zero Hour reference
// (GameLogic/Module/CreateCrateDie.h) proves the class owns an
// AsciiStringList m_crateNameList whose destructor body is just
// { m_crateNameList.clear(); }; the implicit member teardown emits the rest.
// Retail measurements: vtable RVA 0x816394 reinstall, explicit clear() of the
// list at +0x3C (matched _List_base<AsciiString>::clear row), implicit
// _List_base teardown (matched row), string-member teardown at +0x10 via the
// folded AsciiString-member destructor (symbols.csv pin), base teardown via
// the opaque Rva001E3624 dtor (symbols.csv pin). BFME2 adds a string member
// at +0x10 (nulled then set to "" by the ctor at 0x35CC36) that Zero Hour
// has no twin for, so it rides the established AsciiStringMember fold idiom
// (AsciiStringFoldDeleters.cpp precedent). The +0x14/+0x18/+0x1C/+0x38/+0x40
// members are POD in teardown order (retail calls nothing else), so they
// are plain data here; the ctor's unknown callees (0x24C7B3, 0x35C9A6) keep
// the ctor itself a separate project.

// stlport (replica idiom: TU-local _STL list over a forward-declared
// AsciiString emits calls mangled exactly like the ModuleFactory-owned
// _List_base<AsciiString> clear/dtor rows, resolving to them with no pins
// and no local emission beyond the implicit list dtor itself).
namespace _STL {
template <class T> class allocator {};
template <class T, class A = allocator<T> > class _List_base
{
public:
	void *_M_nodeNext;
	void *_M_nodePrev;
	void clear();
	~_List_base();
};
template <class T, class A = allocator<T> > class list : public _List_base<T, A>
{
};
}

class AsciiString;

// Fold-shared AsciiString member teardown (never defined; resolves through
// the symbols.csv pin at 0x36410 like the Bucket/ FoldDeleters bodies).
class AsciiStringMember
{
public:
	~AsciiStringMember();
};

// Opaque ModuleData base (never defined; base-dtor call resolves through
// the symbols.csv pin at 0x1E3624). Retail base body keeps a conditional
// delete pointer at +0x04; +0x08/+0x0C ride as data.
class Rva001E3624
{
public:
	virtual ~Rva001E3624();
	void *m_unk04;
	int m_unk08;
	int m_unk0C;
};

class CreateCrateDieModuleData : public Rva001E3624
{
public:
	virtual ~CreateCrateDieModuleData();
	AsciiStringMember m_unkString10;
	float m_unk14;
	int m_unk18;
	char m_pad1C[0x20];
	_STL::list<AsciiString> m_crateNameList;
};

// ??1CreateCrateDieModuleData@@UAE@XZ
CreateCrateDieModuleData::~CreateCrateDieModuleData()
{
	m_crateNameList.clear();
}
// ??1?$list@VAsciiString@@V?$allocator@VAsciiString@@@_STL@@@_STL@@QAE@XZ present-unmatched
// ??_GCreateCrateDieModuleData@@UAEPAXI@Z present-unmatched
