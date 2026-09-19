// cl: /Od /Ob1

inline bool bfmeBytesEqual(const char &left, const char &right)
{
	return left == right;
}

char *bfmeFindByteCore(char *first, char *last, char wanted, char *state)
{
	int groupCount;

	for (groupCount = (last - first) >> 2; groupCount > 0; --groupCount) {
		if (bfmeBytesEqual(*first, wanted))
			return first;
		first = first + 1;

		if (bfmeBytesEqual(*first, wanted))
			return first;
		first = first + 1;

		if (bfmeBytesEqual(*first, wanted))
			return first;
		first = first + 1;

		if (bfmeBytesEqual(*first, wanted))
			return first;
		first = first + 1;
	}

	switch (last - first) {
	case 3:
		{
			if (bfmeBytesEqual(*first, wanted))
				return first;
			first = first + 1;
		}
	case 2:
		{
			if (bfmeBytesEqual(*first, wanted))
				return first;
			first = first + 1;
		}
	case 1:
		{
			if (bfmeBytesEqual(*first, wanted))
				return first;
		}
	default:
		break;
	}
	return last;
}
