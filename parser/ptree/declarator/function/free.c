
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_function_declarator(
	struct declarator* super)
{
	struct function_declarator* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->inner);
	tfree(this->parameters);
	
	EXIT;
}

