
#include <stdio.h>

#include <enums/error.h>
#include <debug.h>

#include <defines/argv0.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <expression/variable/new.h>

#include <scope/lookup/variable.h>
#include <scope/variable.h>

#include "identifier.h"

int primary_expression_identifier_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line,  unsigned last_column,
	struct scope* scope,
	char* identifier)
{
	int error = 0;
	struct variable* variable = NULL;
	ENTER;
	
	dpvs(identifier);
	
	// lookup variable?
	if (!(variable = scope_lookup_variable(scope, identifier)))
	{
		fprintf(stderr, "%s: use of undeclared variable '%s'!\n", argv0, identifier),
		error = e_bad_input_file;
	}
	else
	{
		error = new_variable_expression((struct variable_expression**) retval,
			first_line, first_column,
			last_line, last_column,
			variable);
	}
	
	tfree(variable);
	tfree(identifier);
	
	EXIT;
	return error;
}

























