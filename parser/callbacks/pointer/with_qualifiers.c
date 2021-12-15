
#include <debug.h>

#include <memory/tfree.h>

#include <parser/ptree/pointer/new.h>

#include "with_qualifiers.h"

int pointer_with_qualifiers_callback(
	struct pointer** out,
	struct type_qualifiers* qualifiers,
	struct pointer* prev)
{
	int error = 0;
	ENTER;
	
	error = new_pointer(out, qualifiers, prev);
	
	tfree(qualifiers), tfree(prev);
	
	EXIT;
	return error;
}

