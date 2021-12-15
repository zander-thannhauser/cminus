
#include <debug.h>

#include <memory/tfree.h>

#include "../struct.h"

#include "layer.h"

void free_layer(void* ptr)
{
	ENTER;
	
	struct layer* this = ptr;
	
	tfree(this->local.variables);
	tfree(this->local.structs);
	tfree(this->local.enums);
	tfree(this->local.types);
	
	EXIT;
}

