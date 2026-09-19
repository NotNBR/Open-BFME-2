// cl: /O2 /DNDEBUG /DWIN32 /D_WINDOWS /MD
// Trimmed BFME1 byte-identical TU: only the placed body below is defined.
// refreshPair is declared-only and resolves via its ledger pin.

class Rva00699180Owner
{
public:
	void refreshPair(int a, int b);
	void refreshAll();
};

void Rva00699180Owner::refreshAll()
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 2; ++j)
			refreshPair(i, j);
	}
}
