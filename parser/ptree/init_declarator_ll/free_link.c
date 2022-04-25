
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_init_declarator_ll_link(
	struct init_declarator_ll_link* this)
{
	tfree(this->element);
	tfree(this->next);
}

