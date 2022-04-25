
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_addressof_expression(struct expression* super)
{
	struct addressof_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->inner);
	
	EXIT;
}

