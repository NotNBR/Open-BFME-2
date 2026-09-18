// cl: /DNDEBUG /MD /EHs-c-

extern "C" int sprintf(char *buffer, const char *format, ...);

struct Rva00891FA0Record
{
    int value;
    int kind;
};

extern int g_rva00891FA0Ready;
extern int g_rva00891FA0Value;
// Retail slots 0x00E17740/44 are not PE imports (no import-table entry), so
// these are .data function pointers, not dllimport functions. Both emit an
// indirect call through the slot; only the symbol identity differs.
extern "C" void (__cdecl *Rva00891FA0SendText)(const char *text);
extern "C" void (__cdecl *Rva00891FA0SendRecord)(
    Rva00891FA0Record *record, int count);

// ?d_00891fa0@@YAXXZ
void d_00891fa0(void)
{
    if (!g_rva00891FA0Ready)
        return;

    char text[16];
    Rva00891FA0Record record;
    sprintf(text, "%06d", g_rva00891FA0Value);
    Rva00891FA0SendText(text);
    record.value = g_rva00891FA0Value;
    record.kind = 3;
    Rva00891FA0SendRecord(&record, 5);
}
