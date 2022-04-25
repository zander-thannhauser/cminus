
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/parameter_ll/append.h>

#include "append.h"

int parameter_list_append_callback(
	struct parameter_ll** out,
	struct parameter_ll* list,
	struct parameter* appendme)
{
	int error = 0;
	ENTER;
	
	error = parameter_ll_append(list, appendme);
	
	if (!error)
		*out = tinc(list);
	
	tfree(list);
	tfree(appendme);
	
	EXIT;
	return error;
}

