
#include <debug.h>

#include "inheritance.h"
#include "struct.h"
#include "build_type.h"

int declarator_build_type(
	char** out_identifier,
	struct type** out_type,
	struct type* base_type,
	struct declarator* this)
{
	int error = 0;
	ENTER;
	
	dpv(this);
	dpv(this->kind);
	dpv(this->inheritance->build_type);
	assert(this->inheritance->build_type);
	
	error = (this->inheritance->build_type)(
		out_identifier,
		out_type,
		base_type,
		this);
	
	EXIT;
	return error;
}













