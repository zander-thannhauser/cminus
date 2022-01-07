
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct/new.h>

#include <scope/lookup/struct.h>
#include <scope/declare/struct.h>

#include "just_identifier.h"

int struct_or_union_specifier_just_identifier_callback(
	struct type** outgoing,
	bool struct_or_union,
	char* identifier,
	struct scope* scope)
{
	int error = 0;
	struct type* stype = NULL;
	ENTER;
	
	stype = scope_lookup_struct(scope, identifier);
	
	if (!stype)
	{
		error = 0
			?: new_incomplete_struct_type((struct struct_type**) &stype, struct_or_union)
			?: scope_declare_struct(scope, identifier, stype);
	}
	
	if (!error)
		*outgoing = tinc(stype);
	
	tfree(identifier);
	tfree(stype);
	
	EXIT;
	return error;
}














