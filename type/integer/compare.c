
#include <debug.h>

#include "struct.h"
/*#include "inheritance.h"*/
#include "compare.h"

int compare_integer_types(
	const struct type* _a,
	const struct type* _b)
{
	int retval = 0;
	const struct integer_type* a = (typeof(a)) _a;
	const struct integer_type* b = (typeof(b)) _b;
	ENTER;
	
	TODO;
	#if 0
	dpv(a->kind);
	dpv(b->kind);
	
	if (a->kind < b->kind)
		retval = -1;
	else if (a->kind > b->kind)
		retval = +1;
	#endif
	
	EXIT;
	return retval;
}




















