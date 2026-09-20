// cl: /O1 /DNDEBUG /MD
// EA BFME1 CommandLine.cpp parseFile; BFME2's live -file table entry
// identifies RVA3BA233 and the complete 63-byte body.
// Initial file is +ABC. The adjacent +AB8 name below is descriptive:
// retail's extended map normalizer writes a timestamped label there.
// Helper identity is based on the full 453-byte body at 3BA06E:
// source-derived slash/token/.map normalization plus BFME2's second output.
template<class T> class StringBase {
    T *data;
public: void set(const T*);
};
class GlobalData {
public:
    char prefix[0xab8];
    StringBase<char> m_bfmeFileLabel;
    StringBase<char> m_initialFile;
};
extern GlobalData *TheWritableGlobalData;
void ConvertShortMapPathToLongMapPath(StringBase<char>&,StringBase<char>&);
int parseFile(char *args[],int num) {
    if(TheWritableGlobalData && num>1) {
        TheWritableGlobalData->m_initialFile.set(args[1]);
        ConvertShortMapPathToLongMapPath(TheWritableGlobalData->m_initialFile,TheWritableGlobalData->m_bfmeFileLabel);
    }
    return 2;
}
