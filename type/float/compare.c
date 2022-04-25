
#include <assert.h>

#include "struct.h"
/*#include "inheritance.h"*/
#include "compare.h"

int compare_float_types(
	const struct type* _a,
	const struct type* _b)
{
	int cmp = 0;
	const struct float_type* a = (typeof(a)) _a;
	const struct float_type* b = (typeof(b)) _b;
	ENTER;
	
	dpv(a->kind);
	dpv(b->kind);
	
	if (a->kind > b->kind)
		cmp = +1;
	else if (a->kind < b->kind)
		cmp = -1;
	
	EXIT;
	return cmp;
}




















