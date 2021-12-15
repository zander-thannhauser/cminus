
#include <string.h>

#include <debug.h>

#include <memory/tinc.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_pointer_type(
	struct pointer_type** new,
	bool qualifiers[number_of_type_qualifiers],
	struct type* dereference)
{
	int error = 0;
	ENTER;
	
	struct pointer_type* this = NULL;
	
	error = new_type(
		(struct type**) &this,
		/* kind: */ tk_pointer,
		/* inheritance: */ &pointer_type_inheritance,
		/* is_complete: */ true,
		/* size: */ sizeof(void*),
		sizeof(*this));
	
	if (!error)
	{
		if (qualifiers)
			memcpy(this->super.qualifiers, qualifiers, sizeof(this->super.qualifiers));
		
		this->dereference = tinc(dereference);
		
		*new = this;
	}
	
	EXIT;
	return error;
}
















