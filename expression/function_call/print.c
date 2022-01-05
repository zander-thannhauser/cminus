
#include <debug.h>

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/

#include <parser/expression_ll/struct.h>

#include <misc/sfprintf.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int function_call_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct expression_link* alink;
	struct function_call_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: expression_print(this->function, stream)
		?: sfprintf(stream, "(");
	
	for (alink = this->arguments->head; !error && alink; alink = alink->next)
	{
		error = expression_print(alink->element, stream);
		
		if (!error && alink->next)
			error = sfprintf(stream, ", ");
	}
	
	if (!error)
		error = sfprintf(stream, ")");
	
	EXIT;
	return error;
}







