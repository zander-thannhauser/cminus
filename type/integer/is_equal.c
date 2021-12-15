
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "is_equal.h"

bool integer_type_is_equal(
	const struct type* _a,
	const struct type* _b)
{
	bool retval = true;
	const struct integer_type* a = (typeof(a)) _a;
	const struct integer_type* b = (typeof(b)) _b;
	ENTER;
	
	dpv(a->kind);
	dpv(b->kind);
	
	retval = a->kind == b->kind;
	
	EXIT;
	return retval;
}




















