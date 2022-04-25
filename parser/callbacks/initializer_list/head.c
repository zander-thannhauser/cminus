
#include <stddef.h>

#include <memory/tinc.h>

#include <memory/tfree.h>

#include <assert.h>

#include <parser/initializer_ll/new.h>
#include <parser/initializer_ll/append.h>

#include "head.h"

int initializer_list_head_callback(
	struct initializer_ll** out,
	struct initializer* element)
{
	int error = 0;
	ENTER;
	
	struct initializer_ll* this = NULL;
	
	error = 0
		?: new_initializer_ll(&this)
		?: initializer_ll_append(this, element);
	
	if (!error)
	{
		*out = tinc(this);
	}
	
	tfree(this);
	tfree(element);
	
	EXIT;
	return error;
}

