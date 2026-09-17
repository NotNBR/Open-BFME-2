// cl: /G6 /arch:SSE /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE
// stlport

// _Rb_tree<const ThingTemplate *, pair<const ThingTemplate *, int>>::
// insert_unique with hint (retail 0x00759DB0, 592 bytes) and without
// (retail 0x00759C80, 145 bytes), the workers behind ScoreKeeper's
// ObjectCountMap insertions. Explicit member instantiation:
// the whole-map form would emit every member and leave this unit full of
// unrowed definitions, and the mangled name needs the const-pointer pair
// (pair<const ThingTemplate * const, int>), not the plain-pointer one.
// _BFME_RETAIL_TREE_INSERT_LAYOUT selects retail's leftmost-fast-path
// spelling; /G6 (not /G7) reproduces retail's register materialization --
// under /G7 the same source compares the root/child links in memory while
// retail loads them (the ushort-key sibling in ConnectionManager.cpp keeps
// the memory form under /G7, so this is key-type pressure, not source).
// The key is a pointer, so a forward declaration carries the instantiation;
// less on pointers needs no definition. ScoreKeeper.cpp itself cannot carry
// the macro: its already-matched map insert/operator[] rows placed from the
// default spelling. Callees pinned in the same commit: _M_insert at
// 0x00759BC0 (9 retail call sites) and the no-hint insert_unique at
// 0x00759C80 (4 sites), both read out of this body's REL32 displacements;
// _M_increment at 0x00024250 resolves through its matched row.

#define _BFME_RETAIL_TREE_INSERT_LAYOUT

#include <map>

class ThingTemplate;

typedef _STL::pair<const ThingTemplate * const, int> ThingTemplateCountPair;

typedef _STL::_Rb_tree<const ThingTemplate *, ThingTemplateCountPair,
	_STL::_Select1st<ThingTemplateCountPair>, _STL::less<const ThingTemplate *>,
	_STL::allocator<ThingTemplateCountPair> > ThingTemplateCountTree;

template ThingTemplateCountTree::iterator
ThingTemplateCountTree::insert_unique(ThingTemplateCountTree::iterator, const ThingTemplateCountPair &);

template _STL::pair<ThingTemplateCountTree::iterator, bool>
ThingTemplateCountTree::insert_unique(const ThingTemplateCountPair &);
