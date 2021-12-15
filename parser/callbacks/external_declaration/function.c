
#include <stdio.h>

#include <debug.h>

/*#include <memory/tinc.h>*/
#include <memory/tfree.h>

/*#include <scope/variable.h>*/

/*#include <parser/variable_ll/struct.h>*/

#include <parser/function_definition/write_asm.h>

#include "function.h"

int external_declaration_function_callback(
	struct function_definition* function,
	struct asm_writer* asm_writer)
{
	int error = 0;
	ENTER;
	
	function_definition_write_asm(function, asm_writer);
	
	tfree(function);
	
	EXIT;
	return error;
}












