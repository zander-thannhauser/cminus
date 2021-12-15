
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_array_type(struct type* super)
{
	struct array_type* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->element_type);
	
	EXIT;
}

