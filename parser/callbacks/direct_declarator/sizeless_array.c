
#include <debug.h>

#include <memory/tfree.h>

#include <parser/ptree/declarator/array/new.h>

#include "sizeless_array.h"

int direct_declarator_sizeless_array_callback(
	struct declarator** out,
	struct declarator* inner)
{
	int error = 0;
	ENTER;
	
	error = new_sizeless_array_declarator(
		(struct array_declarator**) out, inner);
	
	tfree(inner);
	
	EXIT;
	return error;
}

