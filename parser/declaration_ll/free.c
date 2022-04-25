
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_declaration_ll(struct declaration_ll* this)
{
	ENTER;
	
	dpv(this->head);
	dpv(this->tail);
	
	tfree(this->head);
	tfree(this->tail);
	
	EXIT;
}

