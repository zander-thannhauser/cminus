
#include <stdio.h>

#include <assert.h>

#include <memory/tfree.h>

#include <parser/parameter_ll/new.h>

#include <type/function/new.h>

#include "../build_type.h"

#include "struct.h"
#include "build_type.h"

int function_declarator_inheritance_build_type(
	char** out_identifier,
	struct type** out_type,
	struct type* retval_type,
	struct declarator* super)
{
	int error = 0;
	struct function_declarator* this = (typeof(this)) super;
	struct type* ftype = NULL;
	ENTER;
	
	error = 0
		?: new_function_type(
			(struct function_type**) &ftype, retval_type, this->parameters)
		?: declarator_build_type(out_identifier, out_type, ftype, this->inner);
	
	tfree(ftype);
	
	EXIT;
	return error;
}


















