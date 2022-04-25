
#include <stdio.h>

#include <assert.h>

#include <memory/tfree.h>

#include <parser/ptree/declarator/identifier/new.h>
#include <parser/ptree/declarator/pointer/new_from_pointer.h>

#include "pointer.h"

int abstract_declarator_pointer_callback(
	struct declarator** out,
	struct pointer* pointer,
	struct declarator* maybe_inner)
{
	int error = 0;
	ENTER;
	
	if (!maybe_inner)
		error = new_identifier_declarator(
			(struct identifier_declarator**) &maybe_inner, NULL);
	
	if (!error)
		error = new_pointer_declarator_from_pointer(
			(struct declarator**) out, pointer, maybe_inner);
	
	tfree(pointer), tfree(maybe_inner);
	
	EXIT;
	return error;
}

