
#include <string.h>

#include <assert.h>

#include <misc/sfprintf.h>

#include "../print.h"

#include "field/struct.h"
#include "field_ll/struct.h"

#include "struct.h"
#include "print.h"

int struct_type_print(
	const struct type* super,
	char* name,
	FILE* stream)
{
	int error = 0;
	const struct struct_type* const this = (typeof(this)) super;
	ENTER;
	
	error = sfprintf(stream, "struct { ");
	
	struct struct_field_ll_link* sfll;
	
	if (!error)
		sfll = this->fields->head;
	
	for (; !error && sfll; sfll = sfll->next)
	{
		struct struct_field* const ele = sfll->element;
		
		error = 0
			?: type_print(ele->type, ele->name, stream)
			?: sfprintf(stream, "; ");
	}
	
	if (!error)
		error = sfprintf(stream, "}");
	
	if (!error && name)
		error = sfprintf(stream, " %s", name);
	
	EXIT;
	return error;
}
















