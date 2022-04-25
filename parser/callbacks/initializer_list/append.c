
#include <assert.h>

#include <memory/tinc.h>

#include <memory/tfree.h>

#include <parser/initializer_ll/append.h>

#include "append.h"

int initializer_list_append_callback(
	struct initializer_ll** out,
	struct initializer_ll* list,
	struct initializer* element)
{
	int error = 0;
	ENTER;
	
	error = initializer_ll_append(list, element);
	
	if (!error)
	{
		*out = tinc(list);
	}
	
	tfree(list);
	tfree(element);
	
	EXIT;
	return error;
}

