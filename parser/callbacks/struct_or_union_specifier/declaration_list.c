
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct/new.h>

#include <scope/declare/struct.h>

#include "declaration_list.h"

int struct_or_union_specifier_declaration_list_callback(
	struct type** out,
	bool struct_or_union,
	char* identifier,
	struct struct_field_ll* fields,
	struct scope* scope)
{
	int error = 0;
	struct type* outgoing = NULL;
	ENTER;
	
	error = new_struct_type(
		(struct struct_type**) &outgoing, struct_or_union, fields);
	
	if (!error && identifier)
		error = scope_declare_struct(scope, identifier, outgoing);
	
	if (!error)
		*out = tinc(outgoing);
	
	tfree(identifier);
	tfree(fields);
	
	tfree(outgoing);
	
	EXIT;
	return error;
}

