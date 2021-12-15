
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_struct_declarator_ll_link(
	struct struct_declarator_ll_link* this)
{
	tfree(this->element);
	tfree(this->next);
}

