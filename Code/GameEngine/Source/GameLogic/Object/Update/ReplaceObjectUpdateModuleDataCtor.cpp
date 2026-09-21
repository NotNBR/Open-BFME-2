// cl: /O1 /arch:SSE /DNDEBUG /MD /EHsc
// stlport
//
// ??0ReplaceObjectUpdateModuleData@@QAE@XZ, retail 0x004B2AC4, 61 bytes.
// Frameless ctor: true opaque base 0x44EB54 called first (declared throw()
// so it takes no EH state), vtable 0x00C56C78 init-listed second, vector
// member at +0xC8 implicitly built through the folded Vector_base<int> row
// (normal STL materializes the temp allocator; NO_EXCEPTIONS inlines it,
// which V1 proved wrong), 0.0f at +0xD4, 0 at +0xD8, 0 at +0xDC. Factory
// 0x24FCEA news 0xE0. Element type is a TU-local stand-in (fold-identical).

#include <vector>

typedef int Int;

class Rva0044EB54
{
public:
	Rva0044EB54() throw();
};

class ReplaceObjectUpdateModuleData : public Rva0044EB54
{
public:
	ReplaceObjectUpdateModuleData();

private:
	void *m_vtable;
	unsigned char m_pad[0xC8 - 4];
	_STL::vector<Int> m_members;
	float m_radius;
	int m_count;
	unsigned char m_flag;
};

// ??0ReplaceObjectUpdateModuleData@@QAE@XZ
ReplaceObjectUpdateModuleData::ReplaceObjectUpdateModuleData()
	: m_vtable(reinterpret_cast<void *>(0x00C56C78))
{
	m_radius = 0.0f;
	m_count = 0;
	m_flag = 0;
}
