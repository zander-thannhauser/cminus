
struct memory_header
{
	unsigned refcount;
	void (*destructor)(void*);
};

