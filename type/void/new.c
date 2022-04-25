
#include <assert.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_void_type(struct void_type** new)
{
	int error = 0;
	ENTER;
	
	struct void_type* this = NULL;
	
	error = new_type(
		(struct type**) &this,
		/* kind: */ tk_void,
		/* inheritance: */ &void_type_inheritance,
		/* is_complete: */ false,
		/* size: */ -1,
		sizeof(*this));
	
	if (!error)
	{
		*new = this;
	}
	
	EXIT;
	return error;
}

