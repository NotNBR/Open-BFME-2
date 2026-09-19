// cl: /O1 /DNDEBUG /MD

// ShellMenuSchemeLine constructor, retail 0x002004A5 (30B).
// Ported from Open-BFME-1 Code/GameEngine/Source/GameClient/GUI/Shell/ShellMenuScheme.cpp
// (BFME1 0x00580400). Member order follows the ZH header; stores follow the
// donor body order (color before width), each pair y then x to match retail's
// fold of the chained assignment.

typedef int Int;
typedef int Color;

enum
{
	GAME_COLOR_UNDEFINED = 0x00FFFFFF
};

struct ICoord2D
{
	int x;
	int y;
};

class ShellMenuSchemeLine
{
public:
	ShellMenuSchemeLine(void);

private:
	ICoord2D m_startPos;
	ICoord2D m_endPos;
	Int m_width;
	Color m_color;
};

// ??0ShellMenuSchemeLine@@QAE@XZ, retail 0x002004A5 (30B).
ShellMenuSchemeLine::ShellMenuSchemeLine(void)
{
	m_startPos.y = 0;
	m_startPos.x = 0;
	m_endPos.y = 0;
	m_endPos.x = 0;
	m_color = GAME_COLOR_UNDEFINED;
	m_width = 1;
}
