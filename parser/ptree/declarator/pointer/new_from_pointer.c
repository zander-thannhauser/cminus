
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/pointer/struct.h>

#include "new.h"
#include "new_from_pointer.h"

int new_pointer_declarator_from_pointer(
	struct declarator** out,
	struct pointer* pointer,
	struct declarator* inner)
{
	int error = 0;
	struct declarator* subout = NULL;
	ENTER;
	
	if (!pointer)
		*out = tinc(inner);
	else error = 0
		?: new_pointer_declarator_from_pointer(
			&subout, pointer->inner, inner)
		?: new_pointer_declarator(
			(struct pointer_declarator**) out,
			pointer->qualifiers, subout);
	
	tfree(subout);
	
	EXIT;
	return error;
}
