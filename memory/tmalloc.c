
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <enums/error.h>
#include <debug.h>

#include <defines/argv0.h>

#include "header.h"
#include "tmalloc.h"

int tmalloc(void** retval, size_t size, void (*destructor)(void*))
{
	int error = 0;
	struct memory_header* header;
	ENTER;
	
	dpv(size);
	dpv(destructor);
	
	header = malloc(sizeof(*header) + size);
	
	if (!header)
		fprintf(stderr, "%s: malloc(size = %lu): %m\n", argv0, size),
		error = e_out_of_memory;
	else
	{
		header->refcount = 1;
		header->destructor = destructor;
		
		*retval = header + 1;
	}
	
	EXIT;
	return error;
}
