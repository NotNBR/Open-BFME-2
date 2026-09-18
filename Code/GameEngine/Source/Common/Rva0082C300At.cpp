// cl: /Od /Ob0 /DNDEBUG /DWIN32 /D_WINDOWS /MD

class Rva0082C300Buf
{
public:
  char *at(int n);

private:
  // Defined out of this TU: resolves through the existing grow pin at
  // 0x00023A40 (declared-not-defined so the call stays out-of-line).
  void grow();

  char *m_start;
  char *m_finish;
};

char *Rva0082C300Buf::at(int n)
{
  if ((unsigned)n >= (unsigned)(m_finish - m_start))
    grow();
  return m_start + n;
}

// Single-pick claim: BFME1 folds at@Rva0082C300Buf (b1 0x0082C300) and
// at@Rva0082C330Buf (b1 0x0082C330) to identical bytes and game.dat carries
// one body at 0x00024DC0. Only the first spelling is defined here so the TU
// holds one claimed body (one body per address; a second same-range row
// would be an over-claim). The C330 twin is documented here and not rowed.
