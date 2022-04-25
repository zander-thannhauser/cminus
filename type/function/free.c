
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_function_type(struct type* super)
{
	struct function_type* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->return_type);
	tfree(this->parameters);
	
	EXIT;
}

