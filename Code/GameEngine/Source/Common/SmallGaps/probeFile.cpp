// ?probeFile@@YAXPBDPAH@Z
// BFME1 imports these under its own slot names; the retail BFME2 slots are
// msvcr71!fopen + msvcr71!fclose.
extern "C" __declspec(dllimport) void *__cdecl fopen(const char *name, const char *mode);
extern "C" __declspec(dllimport) int __cdecl fclose(void *file);
void probeFile(const char *name, int *status)
{
	void *file = fopen(name, "w");
	*status = (file != 0) ? 0 : 10;
	fclose(file);
}
