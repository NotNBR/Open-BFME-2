// ?getBufferForRead@?$StringBase@D@@QAEPADH@Z
// partial score=0.89017 date=2026-09-20
// cl: /O2 /EHsc
// StringBase buffer layout and API from the BFME1 reference; allocation and
// copy-on-write behavior reconstructed from BFME2 1.06 RVA 0x00036640.
namespace _STL {
template <typename T> class allocator {
public:
    static T *allocate(unsigned int bytes, const void *hint);
};
}
template <typename T> class StringBase {
public:
    T *getBufferForRead(int len);
private:
    void releaseBuffer();
    struct Header {
        int ref_count;
        unsigned short length;
        unsigned short capacity;
        T data[1];
    };
    Header *m_data;
};
template <typename T>
T *StringBase<T>::getBufferForRead(int len)
{
    if (m_data && m_data->capacity > len && m_data->ref_count == 1) {
        m_data->data[m_data->length] = 0;
    } else {
        int bytes = (len + 1) * (int)sizeof(T) + 8;
        if (bytes > 0x7fff)
            throw 1;
        bytes = ((bytes + 3) / 4) * 4;
        Header *data = (Header *)_STL::allocator<char>::allocate(bytes, (const void *)0x737472);
        data->ref_count = 1;
        data->capacity = (unsigned short)((bytes - 8) / (int)sizeof(T));
        data->length = 0;
        data->data[0] = 0;
        releaseBuffer();
        m_data = data;
    }
    if (m_data) {
        m_data->length = (unsigned short)len;
        m_data->data[len] = 0;
    }
    return m_data->data;
}
template char *StringBase<char>::getBufferForRead(int len);
