
#include <stdio.h>

#include <assert.h>

#include <memory/tfree.h>

/*#include <ast/parameter_ll/new.h>*/

#include <type/pointer/new.h>

#include <parser/ptree/type_qualifiers/struct.h>

#include "../build_type.h"

#include "struct.h"
#include "build_type.h"

int pointer_declarator_inheritance_build_type(
	char** out_identifier,
	struct type** out_type,
	struct type* retval_type,
	struct declarator* super)
{
	int error = 0;
	struct pointer_declarator* this = (typeof(this)) super;
	struct pointer_type* ptype = NULL;
	ENTER;
	
	error = 0
		?: new_pointer_type(&ptype, this->qualifiers->qualifiers, retval_type)
		?: declarator_build_type(out_identifier, out_type, (struct type*) ptype, this->inner);
	
	tfree(ptype);
	
	EXIT;
	return error;
}


















