
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_function_call_expression(struct expression* super)
{
	struct function_call_expression *this = (typeof(this)) super;
	ENTER;
	
	tfree(this->function);
	tfree(this->arguments);
	
	EXIT;
}

