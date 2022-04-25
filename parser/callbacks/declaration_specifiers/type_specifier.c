
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/declaration_specifiers/new.h>
#include <parser/ptree/declaration_specifiers/set_type.h>

#include "type_specifier.h"

int declaration_specifiers_type_specifier_callback(
	struct declaration_specifiers** out,
	struct type* type_specifier,
	struct declaration_specifiers* specifiers,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	if (!specifiers)
		error = new_declaration_specifiers(&specifiers);
	
	if (!error)
		error = declaration_specifiers_set_type(specifiers, type_specifier, types);
	
	if (!error)
		*out = tinc(specifiers);
	
	tfree(type_specifier), tfree(specifiers);
	
	EXIT;
	return error;
}















