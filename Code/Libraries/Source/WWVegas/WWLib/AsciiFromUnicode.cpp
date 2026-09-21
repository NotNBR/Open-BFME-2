// cl: /O2 /DNDEBUG /MD /EHsc
// Reference: BFME1 ascii/unicode string construction/translation family.
// Explicit BFME2 export ??0AsciiString@@QAE@ABVUnicodeString@@@Z identifies
// RVA38250 (91 bytes). Its exported wide translate38170 distinguishes it
// from the masked-identical reverse conversion6CB6D0; no duplicate range.
typedef unsigned short Wide;
template<class T> class StringBase {
    T *data;
public:
    StringBase():data(0){}
    void releaseBuffer();
    ~StringBase(){releaseBuffer();}
};
class UnicodeString {
    struct Header { int refs; unsigned short length,capacity; Wide data[1]; };
    Header *data;
public:
    const Wide *str()const {return data?data->data:(const Wide*)L"";}
};
class AsciiString:public StringBase<char> {
public:
    AsciiString(const UnicodeString&);
    void translate(const Wide*);
};
AsciiString::AsciiString(const UnicodeString& text) {
    translate(text.str());
}
