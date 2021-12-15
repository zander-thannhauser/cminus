
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct/field/new.h>
#include <type/struct/field_ll/new.h>
#include <type/struct/field_ll/append.h>

#include <parser/ptree/declarator/build_type.h>

#include <parser/ptree/specifier_qualifiers/struct.h>
#include <parser/ptree/struct_declarator/struct.h>
#include <parser/ptree/struct_declarator_ll/struct.h>

#include "declaration.h"

int struct_declaration_declaration_callback(
	struct struct_field_ll** out,
	struct specifier_qualifiers* sq,
	struct struct_declarator_ll* declarations)
{
	int error = 0;
	struct struct_declarator_ll_link* sdlink;
	ENTER;
	
	struct struct_field_ll* fields = NULL;
	
	error = new_struct_field_ll(&fields);
	
	for (sdlink = declarations->head; !error && sdlink; sdlink = sdlink->next)
	{
		char* identifier = NULL;
		struct type* type = NULL;
		struct struct_field* field = NULL;
		
		error = 0
			?: declarator_build_type(
				&identifier, &type, sq->type,
				sdlink->element->declarator)
			?: new_struct_field(&field, identifier, type)
			?: struct_field_ll_append(fields, field)
			;
		
		tfree(identifier);
		tfree(type);
		tfree(field);
	}
	
	if (!error)
		*out = tinc(fields);
	
	tfree(fields);
	
	tfree(sq), tfree(declarations);
	
	EXIT;
	return error;
}











