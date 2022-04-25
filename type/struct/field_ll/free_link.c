
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_struct_field_ll_link(
	struct struct_field_ll_link* this)
{
	tfree(this->element);
	tfree(this->next);
}

