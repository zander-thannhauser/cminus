
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/statement_ll/append.h>

#include "append.h"

int statement_list_append_callback(
	struct statement_ll** retval,
	struct statement_ll* list,
	struct statement* element)
{
	int error = 0;
	ENTER;
	
	error = statement_ll_append(list, element);
	
	if (!error)
		*retval = tinc(list);
	
	tfree(list);
	tfree(element);
	
	EXIT;
	return error;
}

