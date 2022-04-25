
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/struct_declarator_ll/append.h>

#include "append.h"

int struct_declarator_list_append_callback(
	struct struct_declarator_ll** out,
	struct struct_declarator_ll* list,
	struct struct_declarator* element)
{
	int error = 0;
	ENTER;
	
	error = struct_declarator_ll_append(list, element);
	
	if (!error)
		*out = tinc(list);
	
	tfree(list);
	tfree(element);
	
	EXIT;
	return error;
}

