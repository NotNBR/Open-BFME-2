// cl: /Od /Ob0 /DNDEBUG /DWIN32 /D_WINDOWS /MD

namespace _STL
{
template <class T>
struct char_traits
{
};

template <>
struct char_traits<char>
{
  static void assign(char &, const char &);
};
}

class Rva0082BEC0Copy
{
public:
  void copy(char *first, char *last, char *out);
};

void Rva0082BEC0Copy::copy(char *first, char *last, char *out)
{
  for (; first != last; ++first, ++out)
    _STL::char_traits<char>::assign(*out, *first);
}

// Single-pick claim: BFME1 folds copy@Rva0082BEC0Copy (b1 0x0082BEC0) and
// copy@Rva0082BF40Copy (b1 0x0082BF40) to identical bytes and game.dat
// carries one body at 0x00024A60. Only the first spelling is defined here
// so the TU holds one claimed body (one body per address; a second
// same-range row would be an over-claim). The BF40 twin is documented here
// and not rowed.
