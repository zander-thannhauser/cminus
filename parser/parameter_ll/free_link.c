
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_parameter_link(struct parameter_link* this)
{
	ENTER;
	
	tfree(this->element);
	tfree(this->next);
	
	EXIT;
}

