
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_pointer_declarator(
	struct declarator* super)
{
	struct pointer_declarator* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->qualifiers);
	tfree(this->inner);
	
	EXIT;
}

