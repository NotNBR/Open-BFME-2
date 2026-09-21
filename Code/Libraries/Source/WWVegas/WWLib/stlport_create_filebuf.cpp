/*
 * Copyright (c) 1999
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1999
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */
// STLport 4.5.3: reference X4Iostream.cpp global streams and filebuf factories.
// Modified for BFME2: factories omit exception wrappers as in the matched retail.
// Original stream context also emits the complete920B wide seekoff at149F0.
// cl: /O2 /GR- /EHsc- /Ireference/open-bfme-1/vendor/stlport/src /Ireference/open-bfme-1/vendor/stlport /Ireference/open-bfme-1/vendor/stlport/stl /Ireference/open-bfme-1/vendor/stlport/using /Ireference/open-bfme-1/Code/stlport
#include "stlport_prefix.h"
#include <istream>
#include <stl/_fstream.h>
#include <stdio_streambuf>
#include "aligned_buffer.h"

#ifndef _STLP_USE_NAMESPACES
# define cin _STLP_cin
# define cout _STLP_cout
# define cerr _STLP_cerr
# define clog _STLP_clog
#endif

_STLP_BEGIN_NAMESPACE

#if defined (_STLP_MSVC) || defined(__MWERKS__) || defined (__ICL) || defined (__ISCPP__)
# if defined(__MWERKS__)
#  pragma suppress_init_code on
# else
#  pragma init_seg("STLPORT_NO_INIT")
# endif
_STLP_DECLSPEC istream cin(0);
_STLP_DECLSPEC ostream cout(0);
_STLP_DECLSPEC ostream cerr(0);
_STLP_DECLSPEC ostream clog(0);
_STLP_DECLSPEC wistream wcin(0);
_STLP_DECLSPEC wostream wcout(0);
_STLP_DECLSPEC wostream wcerr(0);
_STLP_DECLSPEC wostream wclog(0);
# if defined(__MWERKS__)
#  pragma suppress_init_code off
# endif
#else
_STLP_DECLSPEC _Stl_aligned_buffer<istream> cin;
_STLP_DECLSPEC _Stl_aligned_buffer<ostream> cout;
_STLP_DECLSPEC _Stl_aligned_buffer<ostream> cerr;
_STLP_DECLSPEC _Stl_aligned_buffer<ostream> clog;
# ifndef _STLP_NO_WCHAR_T
_STLP_DECLSPEC _Stl_aligned_buffer<wistream> wcin;
_STLP_DECLSPEC _Stl_aligned_buffer<wostream> wcout;
_STLP_DECLSPEC _Stl_aligned_buffer<wostream> wcerr;
_STLP_DECLSPEC _Stl_aligned_buffer<wostream> wclog;
# endif
#endif

filebuf* _Stl_create_filebuf(FILE* f, ios_base::openmode mode)
{
  basic_filebuf<char, char_traits<char> >* result;
  result = new basic_filebuf<char, char_traits<char> >();
  result->_M_open(_FILE_fd(f), mode);
  if (!result->is_open()) { delete result; result = 0; }
  return result;
}

#ifndef _STLP_NO_WCHAR_T
wfilebuf* _Stl_create_wfilebuf(FILE* f, ios_base::openmode mode)
{
  basic_filebuf<wchar_t, char_traits<wchar_t> >* result;
  result = new basic_filebuf<wchar_t, char_traits<wchar_t> >();
  result->_M_open(_FILE_fd(f), mode);
  if (!result->is_open()) { delete result; result = 0; }
  return result;
}
#endif

// BFME1 reference alias: BFME2 loc-init release70E0 uses the same
// DDEB18 classic-locale object and DDEB20 counter as the held destructor.
void rva00832100Release(void);

long ios_base::Init::_S_count = 0;

void _STLP_CALL ios_base::_S_uninitialize()
{
  if (Init::_S_count == 0)
    return;

  istream* ptr_cin  = __REINTERPRET_CAST(istream*,&cin);
  ostream* ptr_cout = __REINTERPRET_CAST(ostream*,&cout);
  ostream* ptr_cerr  = __REINTERPRET_CAST(ostream*,&cerr);
  ostream* ptr_clog  = __REINTERPRET_CAST(ostream*,&clog);
# ifndef _STLP_NO_WCHAR_T
  wistream* ptr_wcin  = __REINTERPRET_CAST(wistream*,&wcin);
  wostream* ptr_wcout = __REINTERPRET_CAST(wostream*,&wcout);
  wostream* ptr_wcerr = __REINTERPRET_CAST(wostream*,&wcerr);
  wostream* ptr_wclog = __REINTERPRET_CAST(wostream*,&wclog);
# endif

  ptr_cin->exceptions(0);
  ptr_cout->exceptions(0);
  ptr_cerr->exceptions(0);
  ptr_clog->exceptions(0);
  delete ptr_cin->rdbuf(0);
  delete ptr_cout->rdbuf(0);
  delete ptr_cerr->rdbuf(0);
  delete ptr_clog->rdbuf(0);
  _Destroy(ptr_cin);
  _Destroy(ptr_cout);
  _Destroy(ptr_cerr);
  _Destroy(ptr_clog);
# ifndef _STLP_NO_WCHAR_T
  ptr_wcin->exceptions(0);
  ptr_wcout->exceptions(0);
  ptr_wcerr->exceptions(0);
  ptr_wclog->exceptions(0);
  delete ptr_wcin->rdbuf(0);
  delete ptr_wcout->rdbuf(0);
  delete ptr_wcerr->rdbuf(0);
  delete ptr_wclog->rdbuf(0);
  _Destroy(ptr_wcin);
  _Destroy(ptr_wcout);
  _Destroy(ptr_wcerr);
  _Destroy(ptr_wclog);
# endif
  if (_Loc_init::_S_count > 0)
    rva00832100Release();
  --Init::_S_count;
}

_STLP_END_NAMESPACE
