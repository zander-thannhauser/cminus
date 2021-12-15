
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_array_declarator(
	struct declarator* super)
{
	struct array_declarator* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->inner);
	
	EXIT;
}

