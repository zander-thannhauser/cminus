
#include <string.h>

#include <debug.h>

#include "../namedtype.h"
#include "type.h"

int compare_namedtype(const void* a, const void* b)
{
	int cmp = 0;
	const struct namedtype* A = a, *B = b;
	ENTER;
	
	dpvs(A->name);
	dpvs(B->name);
	
	cmp = strcmp(A->name, B->name);
	
	EXIT;
	return cmp;
}

