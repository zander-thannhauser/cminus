
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "is_equal.h"

bool type_is_equal(
	const struct type* a,
	const struct type* b)
{
	bool retval = true;
	ENTER;
	
	dpv(a);
	dpv(b);
	
	if (a != b)
	{
		int i, n;
		
		dpv(a->kind);
		dpv(b->kind);
		
		if (a->kind != b->kind)
			retval = false;
		
		for (i = 0, n = number_of_type_qualifiers; retval && i < n; i++)
			if (a->qualifiers[i] != b->qualifiers[i])
				retval = false;
		
		if (retval && !a->inheritance->is_equal(a, b))
			retval = false;
		
		dpvb(retval);
	}
	
	EXIT;
	return retval;
}




















