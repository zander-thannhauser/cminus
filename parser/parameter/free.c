
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_parameter(struct parameter* this)
{
	ENTER;
	
	tfree(this->identifier);
	tfree(this->type);
	
	EXIT;
}

