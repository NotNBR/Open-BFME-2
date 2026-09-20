// cl: /DNDEBUG /MD /EHsc
// Retail 0x00689B10 (338B). VideoPlayer::getVideo linear scan over the
// 28-byte Video table: copy/compare each internal name case-insensitively.
// Transferred from the BFME1 reconstruction (VideoPlayerQueries.cpp); only
// getVideo is claimed here. AsciiString carries no user copy/dtor so both
// implicit members emit the shared StringBase base calls retail makes
// (ctor 0x365F0, teardown 0x36410, both via public-spelling pins); trim
// resolves to 0x37CF0.

extern "C" __declspec(dllimport) int __cdecl _memicmp(const void *, const void *, unsigned int);
extern const char Rva006A16B0Empty[];

template <typename T> class StringBase
{
public:
	StringBase(const StringBase &other);
	~StringBase();

private:
	char *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	void trim();
};

struct Video
{
	char m_pad00[4];
	AsciiString m_internalName;
	char m_tail[0x1C - 8];
};

extern Video *g_bfmeVideoTableBegin;
extern Video *g_bfmeVideoTableEnd;

// Read-only view of the canonical StringBase allocation header: refcount+0,
// length+4, capacity+6, text+8. The Video name comparison inlines these reads.
struct VideoNameBufferView
{
    int m_refCount;
    unsigned short m_length;
    unsigned short m_capacity;
    char m_text[1];
};

struct VideoStringStorageView
{
    VideoNameBufferView *m_data;
};

// ?compareVideoNames@@YAHABVAsciiString@@0@Z absent-from-retail
inline int compareVideoNames(const AsciiString &left, const AsciiString &right)
{
    const VideoStringStorageView *self = (const VideoStringStorageView *)&left;
    const VideoStringStorageView *that = (const VideoStringStorageView *)&right;
    int thatLength = that->m_data ? that->m_data->m_length : 0;
    const char *thatText = that->m_data ? that->m_data->m_text : Rva006A16B0Empty;
    int selfLength = self->m_data ? self->m_data->m_length : 0;
    const char *selfText = self->m_data ? self->m_data->m_text : Rva006A16B0Empty;
    int count = selfLength < thatLength ? selfLength : thatLength;
    int result = _memicmp(selfText, thatText, count);
    if (result != 0)
        return result;
    return selfLength - thatLength;
}

class VideoPlayer
{
public:
	virtual const Video *getVideo(AsciiString movieTitle);
};

// ?getVideo@VideoPlayer@@UAEPBUVideo@@VAsciiString@@@Z
const Video *VideoPlayer::getVideo(AsciiString movieTitle)
{
	AsciiString title(movieTitle);
	title.trim();

	Video *it = g_bfmeVideoTableBegin;
	for (; it != g_bfmeVideoTableEnd; ++it)
	{
		AsciiString name(it->m_internalName);
		name.trim();
		if (compareVideoNames(name, title) == 0)
			return it;
	}
	return 0;
}
