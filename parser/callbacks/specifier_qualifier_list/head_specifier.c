
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>
#include <memory/tinc.h>

#include <parser/ptree/specifier_qualifiers/new.h>
#include <parser/ptree/specifier_qualifiers/set_type.h>

#include "head_specifier.h"

int specifier_qualifier_list_head_specifier(
	struct specifier_qualifiers** out,
	struct type* type,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	struct specifier_qualifiers* this = NULL;
	
	error = 0
		?: new_specifier_qualifiers(&this)
		?: specifier_qualifiers_set_type(this, type, types);
	
	if (!error)
		*out = tinc(this);
	
	tfree(type);
	
	tfree(this);
	
	EXIT;
	return error;
}

