
#include <debug.h>

#include <parser/parameter/struct.h>
#include <parser/parameter_ll/struct.h>

#include <misc/sfprintf.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

int function_type_print(
	const struct type* super,
	char* name,
	FILE* stream)
{
	int error = 0;
	const struct function_type* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: type_print(this->return_type, NULL, stream)
		?: sfprintf(stream, " ")
		?: (name ? sfprintf(stream, "%s", name) : 0)
		?: sfprintf(stream, "(");
	
	struct parameter_link* plink;
	
	for (plink = this->parameters->head; !error && plink; plink = plink->next)
	{
		struct parameter* const p = plink->element;
		
		error = type_print(p->type, p->identifier, stream);
		
		if (!error && plink->next)
			error = sfprintf(stream, ", ");
	}
	
	if (!error)
		error = sfprintf(stream, ")");
	
	EXIT;
	return error;
}
















