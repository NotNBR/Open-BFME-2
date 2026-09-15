// cl: /Od /GZ /GS /MD /DNDEBUG
/* EA DirtySock -- one-shot MD5 wrapper, ported verbatim from BFME1
 * Code/GameEngine/Source/GameNetwork/Y4DirtySockHashWrap.c
 * (Rva0080D590, 120B). Retail 0x00679490 (120B Ghidra).
 *
 * Init/update/finish live in Y4CommDigest.c; this TU only stacks a
 * context, feeds it, and writes the digest. Retail names the local
 * MD5 (from the /GZ frame descriptor).
 */

struct Rva00810060Context
{
	unsigned int m_count;
	unsigned int m_state[4];
	unsigned char m_block[0x40];
};

void Rva00810020(struct Rva00810060Context *context);
void Rva00810060(struct Rva00810060Context *context,
	const unsigned char *data, int length);
void Rva00810FF0(struct Rva00810060Context *context, char *out, int outSize);

void Rva0080D590(const unsigned char *data, int length, char *digest)
{
	struct Rva00810060Context MD5;

	Rva00810020(&MD5);
	Rva00810060(&MD5, data, length);
	Rva00810FF0(&MD5, digest, 0x10);
}
