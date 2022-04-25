
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <enums/error.h>
#include <assert.h>

#include <defines/argv0.h>

#include "header.h"
#include "tfree.h"
#include "tmalloc.h"
#include "trealloc.h"

int trealloc(void** retval, size_t size)
{
	int error = 0;
	void* old = *retval;
	
	if (!old)
		error = tmalloc(retval, size, NULL);
	else if (!size)
		tfree(*retval);
	else
	{
		struct memory_header* oldh = old - sizeof(*oldh);
		struct memory_header* newh;
		
		if (!(newh = realloc(oldh, sizeof(*oldh) + size)))
		{
			fprintf(stderr, "%s: realloc(%lu): %m\n", argv0, size),
			error = e_out_of_memory;
		}
		else
		{
			if (newh != oldh)
				newh->refcount = 1;
			
			*retval = (void*) newh + sizeof(*newh);
		}
	}
	return error;
}


















