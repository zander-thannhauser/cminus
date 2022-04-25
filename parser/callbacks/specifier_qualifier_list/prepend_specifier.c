
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/specifier_qualifiers/set_type.h>

#include "prepend_specifier.h"

int specifier_qualifier_list_prepend_specifier(
	struct specifier_qualifiers** out,
	struct type* type_specifier,
	struct specifier_qualifiers* this,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	error = specifier_qualifiers_set_type(this, type_specifier, types);
	
	if (!error)
		*out = tinc(this);
	
	tfree(type_specifier);
	tfree(this);
	
	EXIT;
	return error;
}

