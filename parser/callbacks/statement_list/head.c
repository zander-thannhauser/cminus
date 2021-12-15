
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/statement_ll/new.h>
#include <parser/statement_ll/append.h>

#include "head.h"

int statement_list_head_callback(
	struct statement_ll** new,
	struct statement* element)
{
	int error = 0;
	ENTER;
	
	struct statement_ll* this = NULL;
	
	error = 0
		?: new_statement_ll(&this)
		?: statement_ll_append(this, element);
	
	if (!error)
		*new = tinc(this);
	
	tfree(this);
	tfree(element);
	
	EXIT;
	return error;
}













