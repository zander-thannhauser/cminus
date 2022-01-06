
#include <debug.h>

#include <type/compare.h>

#include "struct.h"
#include "compare.h"

int compare_pointer_types(
	const struct type* _a,
	const struct type* _b)
{
	int retval = true;
	const struct pointer_type* a = (typeof(a)) _a;
	const struct pointer_type* b = (typeof(b)) _b;
	ENTER;
	
	retval = compare_types(a->dereference, b->dereference);
	
	EXIT;
	return retval;
}
