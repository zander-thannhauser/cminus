
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_variable_expression(struct expression* super)
{
	struct variable_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->variable);
	
	EXIT;
}

