
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>

#include <parser/ptree/pointer/new.h>

#include "pointer.h"

int pointer_pointer_callback(
	struct pointer** new,
	struct pointer* prev)
{
	int error = 0;
	ENTER;
	
	error = new_pointer(new, NULL, prev);
	
	tfree(prev);
	
	EXIT;
	return error;
}

