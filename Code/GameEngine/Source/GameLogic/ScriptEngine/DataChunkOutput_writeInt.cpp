// cl: /O1
//
// DataChunkOutput::writeInt, retail 0x00306CFF (24 bytes).
// DataChunkOutput::writeReal, retail 0x00306CFF (24 bytes, ICF-folded).
// Binary chunk writers; the file handle lives at +0x04. Int and float are
// both four bytes on the stack, so the two bodies fold to identical code.

extern "C" __declspec(dllimport) unsigned int __cdecl fwrite(
	const void *ptr, unsigned int size, unsigned int count, void *file);

class DataChunkOutput
{
public:
	void writeInt(int intValue);
	void writeReal(float realValue);

private:
	char pad_0000[4];
	void *file;
};

void DataChunkOutput::writeInt(int intValue)
{
	fwrite(&intValue, 4, 1, file);
}

void DataChunkOutput::writeReal(float realValue)
{
	fwrite(&realValue, 4, 1, file);
}
