// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1
//
// GameLogic game-mode gate leaves called by BFMEDesyncCheck::writeReportIfMismatched:
// the first rejects modes 9/4/7, the second accepts modes 1/5. Retail keeps each
// decision's cold return in a tail block after its own ret (28B/23B true extents,
// proven by raw-byte decode, not the first-ret guess). Member identity is the
// game-mode word at +0x110 (BFME1 carries it at +0x10C; retail is shifted +4,
// the same family as the +0x40 GameLogic frame lesson).

class GameLogic
{
public:
    bool rva0042219(void);
    bool rva0042235(void);

private:
    char m_pad[0x110];
    int m_gameMode;
};

// ?rva0042219@GameLogic@@QAE_NXZ
bool GameLogic::rva0042219(void)
{
    return m_gameMode != 9 && m_gameMode != 4 && m_gameMode != 7;
}

// ?rva0042235@GameLogic@@QAE_NXZ
bool GameLogic::rva0042235(void)
{
    return m_gameMode == 1 || m_gameMode == 5;
}
