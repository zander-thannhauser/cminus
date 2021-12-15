
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_pointer_type(struct type* super)
{
	struct pointer_type* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->dereference);
	
	EXIT;
}

