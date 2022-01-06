
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "compare.h"

int compare_float_types(
	const struct type* _a,
	const struct type* _b)
{
	int retval = true;
	const struct float_type* a = (typeof(a)) _a;
	const struct float_type* b = (typeof(b)) _b;
	ENTER;
	
	TODO;
	#if 0
	dpv(a->kind);
	dpv(b->kind);
	
	retval = a->kind == b->kind;
	#endif
	
	EXIT;
	return retval;
}




















