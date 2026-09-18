// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ob0
//
// ?AsObject@@YAPAVObject@@PAVThing@@@Z, retail 0x00306A5E (16B). Null-guarded
// downcast from Thing to Object through the virtual at slot +0x10.
// Transferred from the BFME1 reconstruction (BFME1 0x00113BC0, 16B, same
// Module.cpp TU family): ZH's Common/Thing.h declares this as a friend
// inline `return thing ? thing->asObjectMeth() : NULL;`, and /Ob0 keeps the
// out-of-line COMDAT copy retail calls. The TU-local Thing declares four
// leading virtuals so asObjectMeth lands at slot +0x10; no vtable is emitted
// here (no key function), so the placeholder slots cost nothing.

class Object;

class Thing
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual Object *asObjectMeth();
};

inline Object *AsObject(Thing *thing) { return thing ? thing->asObjectMeth() : 0; }

// Anchor: forces the inline's out-of-line emission; claims no row.
Object *anchorAsObject(Thing *thing)
{
	return AsObject(thing);
}
