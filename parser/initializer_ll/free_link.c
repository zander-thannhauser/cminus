
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_initializer_ll_link(
	struct initializer_ll_link* this)
{
	tfree(this->element);
	tfree(this->next);
}

