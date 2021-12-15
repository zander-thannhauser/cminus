
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>

#include <parser/parameter/new.h>

#include <parser/ptree/declaration_specifiers/struct.h>
#include <parser/ptree/declarator/build_type.h>

#include "abstract_declarator.h"

int parameter_declaration_abstract_declarator_callback(
	struct parameter** out,
	struct declaration_specifiers* specifiers,
	struct declarator* declarator)
{
	int error = 0;
	ENTER;
	
	char* identifier = NULL;
	struct type* type = NULL;
	
	error = 0
		?: declarator_build_type(
			&identifier, &type, specifiers->type, declarator)
		?: new_parameter(out, identifier, type)
		;
	
	assert(!identifier);
	
	tfree(specifiers);
	tfree(declarator);
	
	tfree(identifier);
	tfree(type);
	
	EXIT;
	return error;
}

