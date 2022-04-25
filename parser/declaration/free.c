
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_declaration(struct declaration* this)
{
	ENTER;
	
	tfree(this->identifier);
	tfree(this->type);
	
	EXIT;
}

