
#include <debug.h>

#include <type/is_equal.h>

#include "struct.h"
#include "is_equal.h"

bool pointer_type_is_equal(
	const struct type* _a,
	const struct type* _b)
{
	bool retval = true;
	const struct pointer_type* a = (typeof(a)) _a;
	const struct pointer_type* b = (typeof(b)) _b;
	ENTER;
	
	retval = type_is_equal(a->dereference, b->dereference);
	
	EXIT;
	return retval;
}
