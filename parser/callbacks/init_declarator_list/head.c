
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/init_declarator_ll/new.h>
#include <parser/ptree/init_declarator_ll/append.h>

#include "head.h"

int init_declarator_ll_head_callback(
	struct init_declarator_ll** retval,
	struct init_declarator* element)
{
	int error = 0;
	struct init_declarator_ll* new = NULL;
	ENTER;
	
	error = 0
		?: new_init_declarator_ll(&new)
		?: init_declarator_ll_append(new, element);
	
	if (!error)
		*retval = tinc(new);
	
	tfree(element);
	tfree(new);
	
	EXIT;
	return error;
}

