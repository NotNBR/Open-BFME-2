// Open-BFME5 conversions.

// BFME1 imports this helper under its own slot name; retail BFME2 slot
// 0x00BBABEC is ole32!CoInitializeEx, so the import is spelled as such here.
extern "C" __declspec(dllimport) long __stdcall CoInitializeEx(void *reserved, unsigned long flags);

class BfmeThingTTD
{
public:
	BfmeThingTTD();
	int m_bfme00;
	int m_bfme04;
	char m_bfme08;
	char m_bfme09;
	char m_bfme0a;
	char m_bfmePad;
	long m_bfmeHr;
	int m_bfme10;
};

BfmeThingTTD::BfmeThingTTD()
{
	m_bfme00 = 0;
	m_bfme04 = 0;
	m_bfme08 = 0;
	m_bfme09 = 0;
	m_bfme0a = 0;
	m_bfmeHr = 0x80004005;
	m_bfme10 = 0;
	m_bfmeHr = CoInitializeEx(0, 6);
}

// NOTE: the donor also defines BfmeThingTTE::bfmeGoTTE (bfmeOpenTTE /
// bfmeBindTTE imports). No byte-identical BFME2 body was served for it, and
// the ledger hook forbids undeclared definitions, so it is trimmed here
// rather than carried unverified.
