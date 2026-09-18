// cl: /DNDEBUG /MD /EHsc

class LineGroupClass
{
public:
	virtual ~LineGroupClass();
};

__declspec(noinline) LineGroupClass::~LineGroupClass() {}

void Force_LineGroup_Deleting_Destructor(LineGroupClass *group)
{
	delete group;
}
