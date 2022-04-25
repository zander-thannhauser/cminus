
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_struct_type(struct type* super)
{
	struct struct_type* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->fields);
	
	EXIT;
}

