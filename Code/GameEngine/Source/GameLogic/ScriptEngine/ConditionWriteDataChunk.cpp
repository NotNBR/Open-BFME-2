// cl: /O1 /EHsc
//
// Condition::WriteConditionDataChunk, retail 0x003B428C (183 bytes).
// Ported from the exact BFME1 reconstruction
// (Code/GameEngine/Source/GameLogic/ScriptEngine/ConditionWriteDataChunk.cpp),
// which matches ZH Scripts.cpp unchanged, with two BFME2 deltas proven by
// the retail body:
// - chunk version 6 (push 6, retail 0x3B42A0), ZH/BFME1 use version 4;
// - two trailing byte fields at Condition+0x4C/+0x4D, each movzx-pushed
//   through DataChunkOutput::writeInt (retail 0x3B4314-0x3B432B), absent in
//   BFME1 (160 bytes vs 183).
// Field offsets from the retail body: m_conditionType at +4, m_numParms at
// +8, m_parms array at +0x0C (12 pointers, MAX_PARMS), m_nextAndCondition at
// +0x3C, extra bytes at +0x4C/+0x4D (Condition : MemoryPoolObject, vtable
// at +0). ConditionTemplate carries m_internalNameKey at +0x10 (vtable +
// three AsciiString slots), read at retail 0x3B42CA.
// Callees openDataChunk/closeDataChunk/writeInt/writeNameKey (DataChunkOutput),
// WriteParameter (Parameter), getConditionTemplate (ScriptEngine) and
// nameToKey (NameKeyGenerator, for NAMEKEY Bogus) are pinned in
// reverse/symbols.csv from this call site's argument shapes; nameToKey is
// already matched at 0x148E1A.

class MemoryPoolObject
{
public:
	virtual ~MemoryPoolObject() {}
};

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *nameString);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class DataChunkOutput
{
public:
	void openDataChunk(char *name, unsigned int ver);
	void writeInt(int value);
	void writeNameKey(NameKeyType key);
	void closeDataChunk(void);
};

class ConditionTemplate
{
public:
	virtual ~ConditionTemplate() {}

	unsigned char m_pad[0x0C];
	NameKeyType m_internalNameKey;
};

class ScriptEngine
{
public:
	const ConditionTemplate *getConditionTemplate(int ndx);
};

extern ScriptEngine *TheScriptEngine;

class Parameter
{
public:
	void WriteParameter(DataChunkOutput &chunkWriter);
};

enum { K_SCRIPT_CONDITION_DATA_VERSION_6 = 6 };
enum { MAX_CONDITION_PARMS = 12 };

class Condition : public MemoryPoolObject
{
public:
	static void WriteConditionDataChunk(DataChunkOutput &chunkWriter, Condition *pCondition);
	Condition *getNext(void) { return m_nextAndCondition; }

	int m_conditionType;
	int m_numParms;
	Parameter *m_parms[MAX_CONDITION_PARMS];
	Condition *m_nextAndCondition;
	int m_hasWarnings;
	int m_customData;
	unsigned int m_customFrame;
	unsigned char m_extraFlagA;
	unsigned char m_extraFlagB;
};

void Condition::WriteConditionDataChunk(DataChunkOutput &chunkWriter, Condition *pCondition)
{
	while (pCondition) {
		chunkWriter.openDataChunk("Condition", K_SCRIPT_CONDITION_DATA_VERSION_6);
		chunkWriter.writeInt(pCondition->m_conditionType);
		const ConditionTemplate *condTemplate = TheScriptEngine->getConditionTemplate(pCondition->m_conditionType);
		if (condTemplate) {
			chunkWriter.writeNameKey(condTemplate->m_internalNameKey);
		} else {
			chunkWriter.writeNameKey(TheNameKeyGenerator->nameToKey("Bogus"));
		}
		chunkWriter.writeInt(pCondition->m_numParms);
		int parmIndex;
		for (parmIndex = 0; parmIndex < pCondition->m_numParms; parmIndex++) {
			pCondition->m_parms[parmIndex]->WriteParameter(chunkWriter);
		}
		chunkWriter.writeInt(pCondition->m_extraFlagA);
		chunkWriter.writeInt(pCondition->m_extraFlagB);
		chunkWriter.closeDataChunk();
		pCondition = pCondition->getNext();
	}
}
