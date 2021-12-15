
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_cast_expression(struct expression* super)
{
	struct cast_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->type);
	tfree(this->inner);
	
	EXIT;
}

