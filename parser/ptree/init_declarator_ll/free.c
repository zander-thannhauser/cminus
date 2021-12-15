
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_init_declarator_ll(
	struct init_declarator_ll* this)
{
	tfree(this->head);
	tfree(this->tail);
}

