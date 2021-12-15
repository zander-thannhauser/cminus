
#include <debug.h>

#include <scope/struct.h>
#include <scope/pop.h>

#include <parser/function_definition/struct.h>

#include "postbody.h"

int function_definition_postbody(
	struct function_definition* funcdef,
	struct scope* scope)
{
	int error = 0;
	ENTER;
	
	if (scope->frame_size % 16)
		scope->frame_size += 16 - scope->frame_size % 16;
	
	funcdef->frame_size = scope->frame_size;
	
	// pop parameter scope:
	scope_pop(scope);
	
	EXIT;
	return error;
}











