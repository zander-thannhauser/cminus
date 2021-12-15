
#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/init_declarator_ll/append.h>

#include "append.h"

int init_declarator_ll_append_callback(
	struct init_declarator_ll** retval,
	struct init_declarator_ll* list,
	struct init_declarator* element)
{
	int error = 0;
	ENTER;
	
	error = init_declarator_ll_append(list, element);
	
	if (!error)
		*retval = tinc(list);
	
	tfree(list);
	tfree(element);
	
	EXIT;
	return error;
}

