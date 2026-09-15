// ?Rva0025B80Scan@@YAPADPAD0D@Z
// partial score=0.85 date=2026-09-15
// cl: /Od /DNDEBUG /MD
// ?Rva0025B80Scan@@YAPADPADH@Z
//
// Byte scanner at 0x0025B80 (349 bytes): search [ptr, end) for byte c
// four-at-a-time with a fallthrough tail, returning the first match or
// end.  Unoptimized (/Od) straight-line code, no calls.  Identity beyond
// the scan behavior is unrecovered, so the name is address-derived.
//
// NOTE: retail booleanizes each byte test without a stack home (pure
// reg neg/sbb/inc plus narrow); this reconstruction uses bool temps and
// carries their homes (+~35B).  Close the gap by finding the home-free
// booleanize spelling if one exists.

char *Rva0025B80Scan(char *ptr, char *end, char c);

// ?Rva0025B80Scan@@YAPADPADH@Z
char *Rva0025B80Scan(char *ptr, char *end, char c)
{
	int count = (end - ptr) >> 2;
	for (; count > 0; count--) {
		bool match0 = (*ptr == c);
		if (match0) {
			return ptr;
		}
		ptr++;
		bool match1 = (*ptr == c);
		if (match1) {
			return ptr;
		}
		ptr++;
		bool match2 = (*ptr == c);
		if (match2) {
			return ptr;
		}
		ptr++;
		bool match3 = (*ptr == c);
		if (match3) {
			return ptr;
		}
		ptr++;
	}
	int remaining = end - ptr;
	switch (remaining) {
	case 3: {
		bool match = (*ptr == c);
		if (match) {
			return ptr;
		}
		ptr++;
	}
	// fallthrough
	case 2: {
		bool match = (*ptr == c);
		if (match) {
			return ptr;
		}
		ptr++;
	}
	// fallthrough
	case 1: {
		bool match = (*ptr == c);
		if (match) {
			return ptr;
		}
		ptr++;
		break;
	}
	default:
		break;
	}
	return end;
}
