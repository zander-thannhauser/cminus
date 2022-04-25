
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_variable_link(struct variable_link* this)
{
	ENTER;
	
	tfree(this->element);
	tfree(this->next);
	
	EXIT;
}

