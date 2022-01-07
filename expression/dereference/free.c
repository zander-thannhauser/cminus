
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_dereference_expression(struct expression* super)
{
	struct dereference_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->inner);
	
	EXIT;
}

