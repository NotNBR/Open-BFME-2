// ?do_insert@KeyToBucketMap@NameKeyGenerator@@AAE?AUinsert_result@12@ABUvalue_type@12@@Z
// partial score=0.75 date=2026-09-14
// cl: /O1 /DNDEBUG /MD
//
// NameKeyGenerator::KeyToBucketMap::insert, retail 0x004DA240, 36 bytes.
// Dedicated TU so NameKeyGenerator.cpp cannot see this body. resize then
// the hashtable insert; count lives at +0x10.

class NameKeyGenerator
{
public:
	class KeyToBucketMap
	{
	public:
		struct value_type
		{
			int first;
			void *second;
		};

		struct Bucket
		{
			Bucket *next;
			int key;
			void *value;
		};

		struct insert_result
		{
			Bucket *first;
			KeyToBucketMap *second;
			bool inserted;

			insert_result() {}
			insert_result(const insert_result &other)
			{
				first = other.first;
				second = other.second;
				inserted = other.inserted;
			}
		};

		insert_result insert(const value_type &value);

	private:
		char pad0[4];
		Bucket **buckets;
		Bucket **bucketEnd;
		char padC[4];
		unsigned m_count;
		void resize(unsigned);
		Bucket *createNode(const value_type &value);
		insert_result do_insert(const value_type &value);
	};
};

NameKeyGenerator::KeyToBucketMap::insert_result
NameKeyGenerator::KeyToBucketMap::insert(const value_type &value)
{
	resize(m_count + 1);
	return do_insert(value);
}

NameKeyGenerator::KeyToBucketMap::insert_result
NameKeyGenerator::KeyToBucketMap::do_insert(const value_type &value)
{
	unsigned bucketCount = (unsigned)(bucketEnd - buckets);
	unsigned key = (unsigned)value.first;
	unsigned bucketIndex = key % bucketCount;
	Bucket *head = buckets[bucketIndex];

	for (Bucket *node = head; node != 0; node = node->next)
	{
		if (node->key == key)
		{
			insert_result found;
			found.first = node;
			found.second = this;
			found.inserted = false;
			return found;
		}
	}

	Bucket *fresh = createNode(value);
	fresh->next = head;
	buckets[bucketIndex] = fresh;
	++m_count;

	insert_result added;
	added.first = fresh;
	added.second = this;
	added.inserted = true;
	return added;
}
