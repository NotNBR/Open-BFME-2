// cl: /O1 /DNDEBUG /MD
// EA BFME1 CommandLine.cpp parseNoShellMap; BFME2 live table81FB58.
// Retail3B945E full32B disables shell map+AF0 and sets adjacent flag+AF1.
// The latter's field name is descriptive, not a claimed original symbol.
class GlobalData {
public:
    char prefix[0xaf0];
    bool m_shellMapOn;
    bool m_bfmeNoShellMapRequested;
};
extern GlobalData *TheWritableGlobalData;
int parseNoShellMap(char *args[],int) {
    if(TheWritableGlobalData) {
        TheWritableGlobalData->m_shellMapOn=false;
        TheWritableGlobalData->m_bfmeNoShellMapRequested=true;
    }
    return 1;
}
