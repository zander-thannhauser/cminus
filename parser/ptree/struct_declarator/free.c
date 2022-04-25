
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_struct_declarator(struct struct_declarator* this)
{
	ENTER;
	
	tfree(this->declarator);
	tfree(this->bitfield_width);
	
	EXIT;
}

