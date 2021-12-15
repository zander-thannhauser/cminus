

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/declaration_specifiers/new.h>
#include <parser/ptree/declaration_specifiers/set_qualifier.h>

#include "type_qualifier.h"

int declaration_specifiers_type_qualifier_callback(
	struct declaration_specifiers** out,
	enum type_qualifier type_qualifier,
	struct declaration_specifiers* inner)
{
	int error = 0;
	ENTER;
	
	if (!inner)
		error = new_declaration_specifiers(&inner);
	
	if (!error)
		error = declaration_specifiers_set_qualifier(inner, type_qualifier);
	
	if (!error)
		*out = tinc(inner);
	
	tfree(inner);
	
	EXIT;
	return error;
}

