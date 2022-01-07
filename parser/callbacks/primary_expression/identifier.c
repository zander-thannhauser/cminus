
#include <stdio.h>

#include <enums/error.h>
#include <debug.h>

#include <defines/argv0.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <expression/variable/new.h>

#include <scope/lookup/variable.h>
#include <scope/variable.h>

#include <parser/yylloc/new.h>

#include "identifier.h"

int primary_expression_identifier_callback(
	struct expression** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line,  unsigned last_column,
	struct scope* scope,
	char* identifier)
{
	int error = 0;
	ENTER;
	
	dpvs(identifier);
	
	// lookup variable?
	struct variable* variable = NULL;
	if (!(variable = scope_lookup_variable(scope, identifier)))
	{
		fprintf(stderr, "%s: use of undeclared variable '%s'!\n", argv0, identifier),
		error = e_bad_input_file;
	}
	
	struct yylloc* loc = NULL;
	
	if (!error)
	{
		error = 0
			?: new_yyloc(&loc, first_line, first_column, last_line, last_column)
			?: new_variable_expression((struct variable_expression**) retval, loc, variable);
	}
	
	tfree(loc);
	tfree(variable);
	tfree(identifier);
	
	EXIT;
	return error;
}

























