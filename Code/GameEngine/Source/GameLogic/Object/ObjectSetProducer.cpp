// cl: /O1 /DNDEBUG /MD
//
// ?setProducer@Object@@QAEXPAV1@@Z,
// retail 0x0028AFD2, 21 bytes. Dedicated TU.
// Stores the producer's object ID (Object+0x74) into this+0x78, or zero when
// given null. Proven by the SpawnBehavior::onDie body at 0x0045F7B5 (push 0 +
// call) per the BFME1 donor SpawnBehavior.cpp:170, plus 31 further raw
// callers game-wide. Sibling at 0x0028AFE7 writes the same ID to +0x7C.

typedef unsigned int ObjectID;

class Object
{
public:
	void setProducer(Object *producer);

private:
	unsigned char m_pad00[0x74];
	ObjectID m_id;
	ObjectID m_producerID;
};

// ?setProducer@Object@@QAEXPAV1@@Z
void Object::setProducer(Object *producer)
{
	m_producerID = producer ? producer->m_id : 0;
}
