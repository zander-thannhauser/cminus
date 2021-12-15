
#include <stdlib.h>

#include <debug.h>

#include "header.h"
#include "tfree.h"

void tfree(void* ptr)
{
	struct memory_header* header;
	ENTER;
	
	if (ptr)
	{
		header = ptr - sizeof(*header);
		
		assert(header->refcount);
		
		if (!--header->refcount)
		{
			dpv(header->destructor);
			
			if (header->destructor)
				(header->destructor)(ptr);
			
			free(header);
		}
		else
		{
			dpv(header->refcount);
		}
	}
	
	EXIT;
}

