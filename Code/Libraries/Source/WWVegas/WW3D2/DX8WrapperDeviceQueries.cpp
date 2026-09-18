// cl: /GX-
// DX8Wrapper device-query leaves:
// ?Rva00116F50@@YA_NXZ @ 0x00116F50 (11B): normalizes
// DX8Wrapper::Set_Next_Render_Device to bool (call + test + setne).
// ?Rva00116F60Get@@YAHXZ @ 0x00116F60 (6B): global dword getter over
// 0x00DEC408 (mov eax,[mem]; ret). Dedicated TU so no caller inlines
// either body (Rva007EB810Get precedent).

class DX8Wrapper
{
protected:
	static bool Set_Next_Render_Device();
	friend bool Rva00116F50();
};

extern int g_Va00DEC408;

// ?Rva00116F50@@YA_NXZ
bool Rva00116F50(void)
{
	unsigned char ok = DX8Wrapper::Set_Next_Render_Device();
	return ok;
}

// ?Rva00116F60Get@@YAHXZ
int Rva00116F60Get(void)
{
	return g_Va00DEC408;
}
