
#include <string.h>

#include <debug.h>

#include <memory/tinc.h>

#include "field/struct.h"
#include "field_ll/struct.h"

#include "struct.h"
#include "get_field.h"

int struct_type_get_field(
	struct struct_field** out,
	struct struct_type* this,
	const char* field_name)
{
	int error = 0;
	struct struct_field* field = NULL;
	struct struct_field_ll_link* link;
	ENTER;
	
	for (link = this->fields->head; !field && link; link = link->next)
		if (!strcmp(link->element->name, field_name))
			field = link->element;
	
	if (!field)
	{
		TODO;
		error = 1;
	}
	
	if (!error)
		*out = tinc(field);
	
	EXIT;
	return error;
}

