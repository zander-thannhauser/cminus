
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>

/*#include <ast/parameter_ll/new.h>*/

#include <type/array/new.h>

/*#include <parser/ptree/parameter_type_ll/struct.h>*/

#include "../build_type.h"

#include "struct.h"
#include "build_type.h"

int array_declarator_inheritance_build_type(
	char** out_identifier,
	struct type** out_type,
	struct type* retval_type,
	struct declarator* super)
{
	int error = 0;
	struct array_declarator* this = (typeof(this)) super;
	struct array_type* atype = NULL;
	ENTER;
	
	error = 0
		?: (this->sizeless
			? new_sizeless_array_type(&atype, retval_type)
			: new_array_type(&atype, retval_type, this->array_size))
		?: declarator_build_type(out_identifier, out_type, (struct type*) atype, this->inner);
	
	tfree(atype);
	
	EXIT;
	return error;
}


















