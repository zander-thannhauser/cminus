
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "pop.h"
#include "free.h"

void free_scope(struct scope* this)
{
	ENTER;
	
	while (this->stackhead)
		scope_pop(this);
	
	tfree(this->global.types);
	tfree(this->global.variables);
	tfree(this->global.structs);
	tfree(this->global.enums);
	
	EXIT;
}

