
#include <debug.h>

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/

#include <parser/expression_ll/struct.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

void function_call_expression_print(
	struct expression* super,
	FILE* stream)
{
	struct expression_link* alink;
	struct function_call_expression* const this = (typeof(this)) super;
	ENTER;
	
	expression_print(this->function, stream);
	
	putc('(', stream);
	
	for (alink = this->arguments->head; alink; alink = alink->next)
	{
		expression_print(alink->element, stream);
		
		if (alink->next)
		{
			fputs(", ", stream);
		}
	}
	
	putc(')', stream);

/*	TODO;*/
	
	EXIT;
}







