
#include <debug.h>

#include "header.h"
#include "tinc.h"

void* real_tinc(void* ptr)
{
	struct memory_header* header;
	ENTER;
	
	dpv(ptr);
	
	if (ptr)
	{
		header = (ptr - sizeof(*header));
		header->refcount++;
		dpv(header->refcount);
	}
	
	EXIT;
	return ptr;
}

