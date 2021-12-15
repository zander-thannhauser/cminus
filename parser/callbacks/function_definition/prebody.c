
#include <stdio.h>

#include <enums/error.h>
#include <debug.h>

#include <defines/argv0.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/function/struct.h>
#include <type/clone_with_qualifiers.h>

#include <scope/push.h>
#include <scope/declare/variable.h>
/*#include <scope/pop.h>*/

#include <parser/parameter/struct.h>
#include <parser/parameter_ll/struct.h>
#include <parser/variable_ll/new.h>
#include <parser/variable_ll/append.h>

#include <parser/function_definition/new.h>
#include <parser/ptree/type_qualifiers/struct.h>
#include <parser/ptree/declarator/build_type.h>
/*#include <parser/ptree/declarator/function/struct.h>*/
#include <parser/ptree/declaration_specifiers/struct.h>

#include "prebody.h"

int function_definition_prebody(
	struct function_definition** out,
	struct declaration_specifiers* specifiers,
	struct declarator* declarator,
	struct scope* scope,
	struct type** retval,
	char** name)
{
	int error = 0;
	ENTER;
	
	if (true
		&& (specifiers->storage_class != sc_default)
		&& (specifiers->storage_class != sc_static))
	{
		fprintf(stderr, "%s: storage class cannot be specified in "
			"function declaration!\n", argv0);
		error = e_bad_input_file;
	}
	
	// cook up function type:
	char* identifier = NULL;
	struct type* base_type = NULL;
	struct type* type = NULL;
	
	if (!error)
		error = 0
			?: type_clone_with_qualifiers(&base_type, specifiers->type, specifiers->qualifiers->qualifiers)
			?: declarator_build_type(&identifier, &type, base_type, declarator);
	
	// idiot-checking:
	if (!error && type->kind != tk_function)
	{
		fprintf(stderr, "%s: function declaration does not declare a "
			"function!\n", argv0);
		error = e_bad_input_file;
	}
	
	struct function_type* const ftype = (struct function_type*) type;
	if (!error && ftype->return_type->kind == tk_array)
	{
		fprintf(stderr, "%s: function return types cannot be of type "
			"array!\n", argv0);
		error = e_bad_input_file;
	}
	
	if (!error)
	{
		*name = identifier;
		*retval = ftype->return_type;
	}
	
	// function definitions come with a free prototype:
	if (!error)
	{
		// grammarically impossible not to have an identifier:
		assert(identifier);
		
		error = scope_declare_variable(scope, identifier, type, sc_default, NULL);
	}
	
	struct variable_ll* paramvars = NULL;
	
	// push parameters into scope,
	// put remember the variables, so the assembler
	// knows enough to copy the parameters from registers to their
	// place in the stack frame:
	if (!error)
		error = 0
			?: new_variable_ll(&paramvars)
			?: scope_push(scope);
	
	struct parameter_link* plink;
	for (plink = ftype->parameters->head;
		!error && plink; plink = plink->next)
	{
		struct parameter* const p = plink->element;
		
		dpvs(p->identifier);
		
		if (!p->identifier)
		{
			TODO;
			error = 1;
		}
		else
		{
			struct variable* variable = NULL;
			
			error = 0
				?: scope_declare_variable(scope, p->identifier, p->type, sc_auto, &variable)
				?: variable_ll_append(paramvars, variable);
			
			tfree(variable);
		}
	}
	
	if (!error)
		error = new_function_definition(
			out, identifier, ftype, specifiers->storage_class, paramvars);
	
	tfree(paramvars);
	tfree(identifier);
	tfree(base_type);
	tfree(type);
	
	EXIT;
	return error;
}











