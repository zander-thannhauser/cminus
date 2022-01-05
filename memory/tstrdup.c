
#include <string.h>

#include <debug.h>

#include "tmalloc.h"
#include "tinc.h"
#include "tfree.h"

#include "tstrdup.h"

int tstrdup(char** out, const char* string)
{
	int error = 0;
	size_t len;
	char* new = NULL;
	ENTER;
	
	dpvs(string);
	
	len = strlen(string);
	
	error = tmalloc((void**) &new, len + 1, NULL);
	
	if (!error)
	{
		memcpy(new, string, len + 1);
		
		*out = new;
	}
	
	EXIT;
	return error;
}

