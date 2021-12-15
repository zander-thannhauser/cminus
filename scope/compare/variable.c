
#include <string.h>

#include <debug.h>

#include "../variable.h"

#include "variable.h"

int compare_variable(const void* a, const void* b)
{
	int cmp = 0;
	const struct variable* A = a, *B = b;
	ENTER;
	
	dpvs(A->name);
	dpvs(B->name);
	
	cmp = strcmp(A->name, B->name);
	
	EXIT;
	return cmp;
}

