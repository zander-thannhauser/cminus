
#include <stdio.h>

#include <debug.h>
#include <error.h>

/*#include <defines/argv0.h>*/

#include <memory/tinc.h>
#include <memory/tfree.h>

/*#include <type/struct.h>*/
/*#include <type/function/struct.h>*/

/*#include <parser/ptree/declaration_specifiers/struct.h>*/
/*#include <parser/ptree/declarator/build_type.h>*/

#include <parser/function_definition/struct.h>

#include "specifiers_and_declarator.h"

int function_definition_with_specifiers_and_declarator(
	struct function_definition** retval,
	struct function_definition* function_definition,
	struct compound_statement* function_body)
{
	int error = 0;
	ENTER;
	
	function_definition->body = tinc(function_body);
	
	*retval = tinc(function_definition);
	
	tfree(function_definition);
	tfree(function_body);
	
	EXIT;
	return error;
}













