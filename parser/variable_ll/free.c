
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_variable_ll(
	struct variable_ll* this)
{
	ENTER;
	
	dpv(this->head);
	dpv(this->tail);
	
	tfree(this->head);
	tfree(this->tail);
	EXIT;
}

