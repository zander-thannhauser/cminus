
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "is_equal.h"

bool float_type_is_equal(
	const struct type* _a,
	const struct type* _b)
{
	bool retval = true;
	const struct float_type* a = (typeof(a)) _a;
	const struct float_type* b = (typeof(b)) _b;
	ENTER;
	
	dpv(a->kind);
	dpv(b->kind);
	
	retval = a->kind == b->kind;
	
	EXIT;
	return retval;
}




















