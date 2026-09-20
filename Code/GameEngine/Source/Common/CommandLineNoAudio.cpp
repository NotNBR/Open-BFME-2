// EA BFME1 CommandLine.cpp parseNoAudio adapted to BFME2's six switches.
// Live -noaudio table81FB68 identifies3B95BB; complete83B body.
// GlobalData fields follow the source audio/music/sounds/3D/speech/video order.
// BFME2CommandFlags is a descriptive name for the retail word at VA DC1170.
// cl: /O1 /DNDEBUG /MD
class GlobalData {
public:
    char prefix[0x99c];
    bool m_audioOn,m_musicOn,m_soundsOn,m_sounds3DOn,m_speechOn,m_videoOn;
};
extern GlobalData *TheWritableGlobalData;
extern unsigned BFME2CommandFlags;
int parseNoAudio(char *args[],int) {
    BFME2CommandFlags|=2;
    if(TheWritableGlobalData) {
        TheWritableGlobalData->m_audioOn=false;
        TheWritableGlobalData->m_speechOn=false;
        TheWritableGlobalData->m_soundsOn=false;
        TheWritableGlobalData->m_sounds3DOn=false;
        TheWritableGlobalData->m_musicOn=false;
        TheWritableGlobalData->m_videoOn=false;
    }
    return 1;
}
