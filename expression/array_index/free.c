
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_array_index_expression(struct expression* super)
{
	struct array_index_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->array);
	tfree(this->index);
	
	EXIT;
}

