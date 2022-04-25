
#include <assert.h>

#include <memory/tinc.h>

#include "struct.h"
#include "build_type.h"

int identifier_declarator_inheritance_build_type(
	char** out_identifier,
	struct type** out_type,
	struct type* base_type,
	struct declarator* super)
{
	int error = 0;
	struct identifier_declarator* this = (typeof(this)) super;
	ENTER;
	
	dpvs(this->identifier);
	
	*out_identifier = tinc(this->identifier);
	*out_type = tinc(base_type);
	
	EXIT;
	return error;
}

