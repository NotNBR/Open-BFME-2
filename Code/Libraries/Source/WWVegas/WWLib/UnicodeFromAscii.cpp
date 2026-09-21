// Reference: BFME1 unicode_string.cpp constructor and translation family,
// reconciled with BFME2's explicitly exported cross-charset constructor.
// Export ??0UnicodeString@@QAE@ABVAsciiString@@@Z identifies6CB6D0 (91B).
// Masked code also matches the reverse conversion at38250; the export and
// callee translate(const char*)6CB5F0 prove this identity independently.
// cl: /O2 /DNDEBUG /MD /EHsc
template<class T> class StringBase {
    T *data;
public:
    StringBase():data(0){}
    void releaseBuffer();
    ~StringBase(){releaseBuffer();}
};
class AsciiString {
    struct Header { int refs; unsigned short length,capacity; char data[1]; };
    Header *data;
public:
    const char *str()const {return data?data->data:"";}
};
class UnicodeString:public StringBase<unsigned short> {
public:
    UnicodeString(const AsciiString&);
    void translate(const char*);
};
UnicodeString::UnicodeString(const AsciiString& text) {
    translate(text.str());
}
