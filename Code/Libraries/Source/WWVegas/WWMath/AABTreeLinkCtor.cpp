// cl: /O1 /DNDEBUG /MD /EHsc
//
// ??0AABTreeLinkClass@@QAE@PAVAABTreeCullSystemClass@@@Z, retail 0x0066F0E0,
// 29 bytes.
//
// AAB-tree cull link: the primary CullLinkClass base holds the owning system
// at +0x04 (its inline ctor runs first, which is why the system store
// precedes the vtable install), then the derived vtable, then three
// null links. Layout follows the Zero Hour reference
// (WWMath/aabtreecull.h: Node at +0x08, NextObject at +0x0C); the third word
// at +0x10 is BFME2-new (the retail `new` site passes sizeof 0x14, and the
// sibling dtor at ~0x66EFC0 guards it exactly like Node/NextObject).
// Its exact class is unproven, so it stays an opaque pointer here.

class CullSystemClass
{
public:
	virtual ~CullSystemClass() { }
};

class AABTreeCullSystemClass : public CullSystemClass
{
};

class CullLinkClass
{
public:
	CullLinkClass(CullSystemClass *system) { System = system; }
	virtual ~CullLinkClass() { }

protected:
	CullSystemClass *System;		// +0x04
};

class AABTreeNodeClass;
class CullableClass;

class AABTreeLinkClass : public CullLinkClass
{
public:
	AABTreeLinkClass(AABTreeCullSystemClass *system);

	AABTreeNodeClass *Node;			// +0x08 partition node containing this object
	CullableClass *NextObject;		// +0x0C next object in the node
	void *m_thirdLink;				// +0x10 BFME2-added guarded pointer (class unproven)
};

// ??0AABTreeLinkClass@@QAE@PAVAABTreeCullSystemClass@@@Z
AABTreeLinkClass::AABTreeLinkClass(AABTreeCullSystemClass *system) :
	CullLinkClass(system),
	Node(0),
	NextObject(0),
	m_thirdLink(0)
{
}
