
#include <debug.h>

#include "../new.h"

#include "struct.h"
#include "clone_with_qualifiers.h"

int integer_type_clone_with_qualifiers(
	struct type** nnew,
	const struct type* tthis,
	bool qualifiers[number_of_type_qualifiers])
{
	int error = 0;
	const struct integer_type** new = (typeof(new)) nnew;
	const struct integer_type* this = (typeof(this)) tthis;
	ENTER;
	
	struct integer_type* that = NULL;
	
	error = new_type(
		(struct type**) &that,
		/* kind: */ tk_integer,
		/* inheritance: */ tthis->inheritance,
		/* is_complete: */ true,
		/* size: */ tthis->size,
		sizeof(*that));
	
	if (!error)
	{
		int i, n;
		
		for (i = 0, n = number_of_type_qualifiers; i < n; i++)
			that->super.qualifiers[i] = tthis->qualifiers[i] || qualifiers[i];
		
		that->kind = this->kind;
		
		*new = that;
	}
	
	EXIT;
	return error;
}



