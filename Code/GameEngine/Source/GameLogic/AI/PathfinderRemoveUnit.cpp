// cl: /DNDEBUG /MD /EHsc
// ?removeUnitFromPathfindMap@Pathfinder@@QAEXPAVObject@@@Z
// Retail 0x006D5CB0, 27 bytes. Dedicated TU.
// Zero Hour AIPathfind.cpp verbatim (Pathfinder::removeUnitFromPathfindMap
// calls removePos plus removeGoal on the unit).

class Object;

class __declspec(novtable) Pathfinder
{
public:
	void removePos(Object *obj);
	void removeGoal(Object *obj);

// ?removeUnitFromPathfindMap@Pathfinder@@QAEXPAVObject@@@Z
	void removeUnitFromPathfindMap(Object *obj);
};

// ?removeUnitFromPathfindMap@Pathfinder@@QAEXPAVObject@@@Z
void Pathfinder::removeUnitFromPathfindMap(Object *obj)
{
	removePos(obj);
	removeGoal(obj);
}
