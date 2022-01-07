
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>

#include <type/clone_with_qualifiers.h>

#include <parser/ptree/specifier_qualifiers/struct.h>
#include <parser/ptree/declarator/build_type.h>
#include <parser/ptree/type_qualifiers/struct.h>

#include "qualifier_list_and_abstract_declarator.h"

int type_name_qualifier_list_and_abstract_declarator(
	struct type** retval,
	struct specifier_qualifiers* sq,
	struct declarator* declarator)
{
	int error = 0;
	struct type* base_type = NULL;
	ENTER;
	
	char* identifier = NULL;
	
	error = 0
		?: type_clone_with_qualifiers(
			&base_type, sq->type, sq->qualifiers->qualifiers)
		?: declarator_build_type(
			&identifier, retval, base_type, declarator);
	
	assert(!identifier);
	
	tfree(sq);
	tfree(declarator);
	tfree(base_type);
	
	EXIT;
	return error;
}













