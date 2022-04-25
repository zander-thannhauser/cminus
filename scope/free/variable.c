
#include <assert.h>

#include <memory/tfree.h>

#include "../variable.h"

#include "variable.h"

void free_variable(void* ptr)
{
	struct variable* this = ptr;
	ENTER;
	
	dpv(this);
	
	dpvs(this->name);
	
	tfree(this->name);
	tfree(this->type);
	
	EXIT;
}

