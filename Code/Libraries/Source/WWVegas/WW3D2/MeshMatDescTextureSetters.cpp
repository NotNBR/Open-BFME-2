// cl: /O2 /G7 /DNDEBUG /MD
// EA Zero Hour meshmatdesc.cpp setters adapted to BFME2 owning handles.
// Single slots at +0x78; indexed buffer array pointer at +8. Each assignment
// AddRefs the new texture before releasing the old one and replacing the slot.
// Release_Ref at61ED10 and Get_Texture_Array at15D360 are existing matched bodies.
class TextureBaseClass { public: void Release_Ref(); };
class TextureClass : public TextureBaseClass {
public: void Add_Ref() { ++*reinterpret_cast<unsigned short *>(reinterpret_cast<char *>(this)+4); }
};
template<class T> class RefCountPtr {
public:
    T *p;
    RefCountPtr &operator=(const RefCountPtr &other) {
        if(other.p) other.p->Add_Ref();
        if(p) p->Release_Ref();
        p=other.p;
        return *this;
    }
};
class TexBufferClass {
    char prefix[8];
    RefCountPtr<TextureClass> *Array;
public: RefCountPtr<TextureClass> *Get_Array() { return Array; }
};
class MeshMatDescClass {
    char prefix[0x78];
    RefCountPtr<TextureClass> Textures[4][2];
public:
    TexBufferClass *Get_Texture_Array(int,int,bool);
    void Set_Single_Texture(const RefCountPtr<TextureClass>&,int,int);
    void Set_Texture(int,const RefCountPtr<TextureClass>&,int,int);
};
void MeshMatDescClass::Set_Single_Texture(const RefCountPtr<TextureClass>& texture,int pass,int stage) {
    Textures[pass][stage]=texture;
}
