
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_unary_expression(struct expression* super)
{
	struct unary_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->inner);
	
	EXIT;
}

