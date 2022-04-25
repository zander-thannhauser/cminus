
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_struct_field_ll(
	struct struct_field_ll* this)
{
	tfree(this->head);
	tfree(this->tail);
}

