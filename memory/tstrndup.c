
#include <string.h>

#include <debug.h>

#include "tmalloc.h"
#include "tstrndup.h"

int tstrndup(char ** out, const char *s, size_t n)
{
	int error = 0;
	size_t len;
	char* new = NULL;
	ENTER;
	
	dpvsn(s, n);
	
	len = strnlen(s, n);
	
	error = tmalloc((void**) &new, len + 1, NULL);
	
	if (!error)
	{
		memcpy(new, s, len);
		new[len] = '\0';
		
		*out = new;
	}
	
	EXIT;
	return error;
}

