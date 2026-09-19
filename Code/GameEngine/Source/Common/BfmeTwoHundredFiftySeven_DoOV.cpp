// cl: /Od /Ob1

char *bfmeFindByteInRange(char *rangeFirst, char *rangeLast, char wanted);

inline bool bfmeQueryAbsentFromSet(void *&setFirst, void *&setLast, char &query, void *&limit)
{
	return bfmeFindByteInRange((char *)setFirst, (char *)setLast, query) == (char *)limit;
}

/* NOTE: the byte locals below are deliberately named out of site order.
   MSVC 7.1 assigns frame homes by identifier hash rather than source order,
   and this permutation is the one that reproduces retail's frame layout.
   Each site still follows the same loaded-then-query pattern. */
void *bfmeDoOV(void *first, void *last, void *setFirst, void *setLast, unsigned char *state)
{
	int groupCount;

	for (groupCount = ((char *)last - (char *)first) >> 2; groupCount > 0; --groupCount) {
		char loadedC;
		char queryD = *(char *)first;
		loadedC = queryD;
		if (bfmeQueryAbsentFromSet(setFirst, setLast, loadedC, setLast))
			return first;
		first = (char *)first + 1;

		char queryC;
		char loadedA = *(char *)first;
		queryC = loadedA;
		if (bfmeQueryAbsentFromSet(setFirst, setLast, queryC, setLast))
			return first;
		first = (char *)first + 1;

		char loadedD;
		char queryA = *(char *)first;
		loadedD = queryA;
		if (bfmeQueryAbsentFromSet(setFirst, setLast, loadedD, setLast))
			return first;
		first = (char *)first + 1;

		char loadedB;
		char queryB = *(char *)first;
		loadedB = queryB;
		if (bfmeQueryAbsentFromSet(setFirst, setLast, loadedB, setLast))
			return first;
		first = (char *)first + 1;
	}

	switch ((char *)last - (char *)first) {
	case 3:
		{
			char queryE;
			char loadedE = *(char *)first;
			queryE = loadedE;
			if (bfmeQueryAbsentFromSet(setFirst, setLast, queryE, setLast))
				return first;
			first = (char *)first + 1;
		}
	case 2:
		{
			char loadedF;
			char queryF = *(char *)first;
			loadedF = queryF;
			if (bfmeQueryAbsentFromSet(setFirst, setLast, loadedF, setLast))
				return first;
			first = (char *)first + 1;
		}
	case 1:
		{
			char loadedG;
			char queryG = *(char *)first;
			loadedG = queryG;
			if (bfmeQueryAbsentFromSet(setFirst, setLast, loadedG, setLast))
				return first;
		}
	default:
		break;
	}
	return last;
}
