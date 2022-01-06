
#include <assert.h>
#include <stdlib.h>

#include "header.h"
#include "tfree.h"

void tfree(void* ptr)
{
	struct memory_header* header;
	
	if (ptr)
	{
		header = ptr - sizeof(*header);
		
		assert(header->refcount);
		
		if (!--header->refcount)
		{
			if (header->destructor)
				(header->destructor)(ptr);
			
			free(header);
		}
	}
}

