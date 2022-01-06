
#include "header.h"
#include "tinc.h"

void* real_tinc(void* ptr)
{
	struct memory_header* header;
	
	if (ptr)
	{
		header = (ptr - sizeof(*header));
		header->refcount++;
	}
	
	return ptr;
}

