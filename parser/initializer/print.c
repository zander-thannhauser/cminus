
#include <debug.h>

#include <expression/print.h>

#include <misc/sfprintf.h>

#include <parser/initializer_ll/struct.h>

#include "struct.h"
#include "print.h"

int initializer_print(
	struct initializer* this,
	FILE* stream)
{
	int error = 0;
	ENTER;
	
	switch (this->kind)
	{
		case ik_expression:
		{
			error = expression_print(this->expression, stream);
			break;
		}
		
		case ik_initializer_list:
		{
			struct initializer_ll_link* ill;
			
			error = sfprintf(stream, "{");
			
			for (ill = this->initializer_ll->head; !error && ill; ill = ill->next)
			{
				error = initializer_print(ill->element, stream);
				
				if (!error && ill->next)
					error = sfprintf(stream, ", ");
			}
			
			if (!error)
				error = sfprintf(stream, "}");
			break;
		}
	}
	
	EXIT;
	return error;
}

















