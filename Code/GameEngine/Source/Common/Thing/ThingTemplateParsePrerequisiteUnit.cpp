// cl: /O1 /DNDEBUG /MD /EHsc
// stlport
// Retail RE: ?parsePrerequisiteUnit@@YAXPAVINI@@PAX1PBX@Z @0x0033EA47 (118B).
//
// BFME1 donor: Code/GameEngine/Source/Common/Thing/ThingTemplate_parsePrerequisites_Thunk.cpp
// (ParsePrerequisiteUnitThunk.cpp: default prereq + throwing-first-token loop
// with in-place AsciiString temp + addUnitPrereq(unit, orFlag) + push_back).
// BFME2 adaptations: getNextToken(0)/getNextTokenOrNull(0) seps-pointer forms
// (matched row + existing OrNull pin), addUnitPrereq outlined to 0x004F52CB
// (new pin, BFME1 (AsciiString,bool) mangling), AsciiString temp built
// directly in the outgoing-arg slot (mov ecx,esp) via the delegating inline
// ctor over the matched private StringBase<char> ctor row 0x37BA0. /O1 for
// the outlined __EH_prolog head (pool-key law), same as the Science twin.
// Shares the Science TU's replica-vector idiom and its ctor/dtor/push_back pins.

enum ScienceType
{
	SCIENCE_INVALID = 0
};

namespace _STL
{

template <class T>
class allocator
{
};

template <class T, class A = allocator<T> >
class vector
{
public:
	void push_back(const T &x);

private:
	T *m_start;
	T *m_finish;
	T *m_end;
};

}

class INI
{
public:
	const char *getNextToken(const char *seps);
	const char *getNextTokenOrNull(const char *seps);
	static ScienceType scanScience(const char *token);
};

template <typename T>
struct StringInlineData
{
	int m_refCount;
	int m_length;
	T m_text[1];
};

template <typename T>
class StringBase
{
	friend class AsciiString;

private:
	StringBase() : m_data(0) {}
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase();

	StringInlineData<T> *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString() : StringBase<char>() {}
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

class ProductionPrerequisite
{
public:
	ProductionPrerequisite();
	~ProductionPrerequisite();

	void addUnitPrereq(AsciiString unit, bool orUnitWithPrevious);

public:
	_STL::vector<int> m_prereqUnits;
	_STL::vector<ScienceType> m_prereqSciences;
	_STL::vector<ScienceType> m_unused;
};

void __cdecl parsePrerequisiteUnit(INI *ini, void *instance, void *, const void *)
{
	_STL::vector<ProductionPrerequisite> *prerequisites =
		static_cast<_STL::vector<ProductionPrerequisite> *>(instance);

	ProductionPrerequisite prerequisite;
	bool orUnitWithPrevious = false;
	for (const char *token = ini->getNextToken(0); token != 0;
		token = ini->getNextTokenOrNull(0))
	{
		prerequisite.addUnitPrereq(AsciiString(token), orUnitWithPrevious);
		orUnitWithPrevious = true;
	}

	prerequisites->push_back(prerequisite);
}
