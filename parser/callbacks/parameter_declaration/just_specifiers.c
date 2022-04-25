
#include <stdio.h>

#include <assert.h>

#include <memory/tfree.h>

#include <parser/parameter/new.h>

#include <parser/ptree/declaration_specifiers/struct.h>

#include "just_specifiers.h"

int parameter_declaration_just_specifiers_callback(
	struct parameter** out,
	struct declaration_specifiers* specifiers)
{
	int error = 0;
	ENTER;
	
	error = new_parameter(out, NULL, specifiers->type);
	
	tfree(specifiers);
	
	EXIT;
	return error;
}

