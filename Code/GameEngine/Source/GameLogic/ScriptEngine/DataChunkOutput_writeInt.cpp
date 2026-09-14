// cl: /O1
//
// DataChunkOutput::writeInt, retail 0x00306CFF (24 bytes).
// Binary chunk writer; the file handle lives at +0x04.

extern "C" __declspec(dllimport) unsigned int __cdecl fwrite(
	const void *ptr, unsigned int size, unsigned int count, void *file);

class DataChunkOutput
{
public:
	void writeInt(int value);

private:
	char pad_0000[4];
	void *file;
};

void DataChunkOutput::writeInt(int value)
{
	fwrite(&value, 4, 1, file);
}
