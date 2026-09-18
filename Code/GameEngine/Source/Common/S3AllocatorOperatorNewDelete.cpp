// BFME1 byte-identical donor: reference/open-bfme-1/Code/GameEngine/Source/Common/S3AllocatorOperatorNewDelete.cpp
// Trimmed to the bodies that reproduce game.dat bytes. Each carried body is a
// separate class operator new/delete through the Gen007EFFC0 allocator; the
// donor names each after its own address rather than guessing pairs.
// ICF note: 0x0065D010 folds the two operator-new twins and 0x0065D030 folds
// the two operator-delete twins, so each address carries a single pick.

class GenAlloc
{
public:
	virtual void v0();
	virtual void v1();
	virtual void *allocate(unsigned int size, int flags);
	virtual void release(void *block, int flags);
};

extern GenAlloc *Gen007EFFC0();

class Gen007F0130
{
public:
	static void *operator new(unsigned int size);
};

// ??2Gen007F0130@@SAPAXI@Z
void *Gen007F0130::operator new(unsigned int size)
{
	return Gen007EFFC0()->allocate(size, 0);
}
