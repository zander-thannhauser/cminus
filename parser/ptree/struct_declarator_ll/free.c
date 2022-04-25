
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_struct_declarator_ll(
	struct struct_declarator_ll* this)
{
	tfree(this->head);
	tfree(this->tail);
}

