
#include <debug.h>

#include <parser/ptree/type_qualifiers/mark_qualifier.h>

#include "struct.h"
#include "set_qualifier.h"

int declaration_specifiers_set_qualifier(
	struct declaration_specifiers* this,
	enum type_qualifier qualifier)
{
	int error = 0;
	ENTER;
	
	type_qualifiers_mark_qualifier(this->qualifiers, qualifier);
	
	EXIT;
	return error;
}

