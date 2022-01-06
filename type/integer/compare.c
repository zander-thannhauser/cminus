
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "compare.h"

int compare_integer_types(
	const struct type* _a,
	const struct type* _b)
{
	bool retval = true;
	const struct integer_type* a = (typeof(a)) _a;
	const struct integer_type* b = (typeof(b)) _b;
	ENTER;
	
	dpv(a->kind);
	dpv(b->kind);
	
	TODO;
	#if 0
	retval = a->kind == b->kind;
	#endif
	
	EXIT;
	return retval;
}




















