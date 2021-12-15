
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/struct_declarator_ll/new.h>
#include <parser/ptree/struct_declarator_ll/append.h>

#include "head.h"

int struct_declarator_list_head_callback(
	struct struct_declarator_ll** out,
	struct struct_declarator* head)
{
	int error = 0;
	ENTER;
	
	struct struct_declarator_ll* ll = NULL;
	
	error = 0
		?: new_struct_declarator_ll(&ll)
		?: struct_declarator_ll_append(ll, head);
	
	if (!error)
		*out = tinc(ll);
	
	tfree(ll);
	tfree(head);
	
	EXIT;
	return error;
}

