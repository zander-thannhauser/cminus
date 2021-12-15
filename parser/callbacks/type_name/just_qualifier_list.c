
#include <debug.h>

#include <memory/tfree.h>

#include <type/clone_with_qualifiers.h>

#include <parser/ptree/type_qualifiers/struct.h>
#include <parser/ptree/specifier_qualifiers/struct.h>

#include "just_qualifier_list.h"

int type_name_just_qualifier_list(
	struct type** out,
	struct specifier_qualifiers* sq)
{
	int error = 0;
	ENTER;
	
	error = type_clone_with_qualifiers(out, sq->type, sq->qualifiers->qualifiers);
	
	tfree(sq);
	
	EXIT;
	return error;
}

