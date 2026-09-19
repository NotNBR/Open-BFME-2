// cl: /DNDEBUG /MD /EHsc
// ??4Dict@@QAEAAV0@ABV0@@Z, retail 0x003133E1 (35B). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/Dict.cpp (BFME1 0x00068290). Trimmed to the
// placed copy-assign body; the rest of the dictionary is declared-only here.
// validate() is inline-empty in the retail header (the .cpp assert body is
// DEBUG-only), so the only call is releaseData, which resolves via the new
// ledger pin at 0x0031339C (same-class private; Ghidra 69B body).

class Dict
{
public:
	Dict &operator=(const Dict &src);

private:
	struct DictPairData
	{
		unsigned short m_refCount;
	};

	void validate() const {}
	void releaseData();

	DictPairData *m_data;
};

// ??4Dict@@QAEAAV0@ABV0@@Z
Dict &Dict::operator=(const Dict &src)
{
	validate();
	if (&src != this)
	{
		releaseData();
		m_data = src.m_data;
		if (m_data)
			++m_data->m_refCount;
	}
	validate();
	return *this;
}
