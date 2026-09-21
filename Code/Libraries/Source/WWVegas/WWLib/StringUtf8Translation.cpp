// Reference: EA UnicodeString.cpp translate/buffer-lifetime family;
// BFME2's explicit exports prove the modernized StringBase API identities.
// Retail uses two-pass UTF-8 conversion through the independently recovered
// platform wrappers. Empty/failed input releases the buffer; success stores
// the written character count excluding the terminator in the 16-bit length.
// cl: /O2 /DNDEBUG /MD
typedef unsigned short Wide;
int BFME2Utf8ToWide(const char*,int,Wide*,int);
int BFME2WideToUtf8(const Wide*,int,char*,int);
template<class T> class CharSource;
class UnicodeString;
template<class T> class StringBase {
    friend class UnicodeString;
    friend class AsciiString;
    struct Header { int refs; unsigned short length,capacity; T data[1]; };
    Header *data;
    void ensureUniqueBufferOfSize(int,bool,const CharSource<T>*,const CharSource<T>*);
    void releaseBuffer();
};
class UnicodeString:public StringBase<Wide> {
public: void translate(const char*);
};
void UnicodeString::translate(const char* text) {
    if(text && *text) {
        int length=BFME2Utf8ToWide(text,-1,0,0);
        ensureUniqueBufferOfSize(length-1,false,0,0);
        int written=BFME2Utf8ToWide(text,-1,data->data,length);
        if(written) {
            data->length=written-1;
            return;
        }
    }
    releaseBuffer();
}
class AsciiString:public StringBase<char> {
public: void translate(const Wide*);
};
void AsciiString::translate(const Wide* text) {
    if(text && *text) {
        int length=BFME2WideToUtf8(text,-1,0,0);
        ensureUniqueBufferOfSize(length-1,false,0,0);
        int written=BFME2WideToUtf8(text,-1,data->data,length);
        if(written) {
            data->length=written-1;
            return;
        }
    }
    releaseBuffer();
}
