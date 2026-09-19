// Virtual FOURCC tag getters, each `mov eax,imm32; ret` (6B).
// These return a four-character code identifying a concrete type
// (animation, mesh, trap, ...). The bodies are byte-exact; the mangled
// names carry the retail address where the real class identity is still
// unknown, and should be repointed if that type is ever identified from
// a vtable or call site. Split from SubsystemNameGetters to keep the
// string and integer constant lanes conflict-free.

class Rva0014CDB5FourCC
{
public:
	int getTag() const;
};

int Rva0014CDB5FourCC::getTag() const
{
	// 'MINA' (0x414E494D).
	return 0x414E494D;
}
