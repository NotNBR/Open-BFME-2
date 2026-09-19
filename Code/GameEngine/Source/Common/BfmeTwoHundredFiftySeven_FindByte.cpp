// cl: /Od

char *bfmeFindByteCore(char *first, char *last, char wanted, char *state);

char *bfmeFindByteInRange(char *rangeFirst, char *rangeLast, char wanted)
{
	char dummy;
	int spare;

	return bfmeFindByteCore(rangeFirst, rangeLast, wanted, &dummy);
}
