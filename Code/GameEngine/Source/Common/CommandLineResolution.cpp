// cl: /O1 /DNDEBUG /MD
// EA BFME1 CommandLine.cpp parseXRes/parseYRes reference flow.
// BFME2 live -xres table81FB70 identifies3B969B (45B); field is +30.
#include <stdlib.h>
class GlobalData {
public:
    char prefix[0x30];
    int m_xResolution;
    int m_yResolution;
};
extern GlobalData *TheWritableGlobalData;
int parseXRes(char *args[],int num) {
    if(TheWritableGlobalData && num>1) {
        TheWritableGlobalData->m_xResolution=atoi(args[1]);
        return 2;
    }
    return 1;
}
