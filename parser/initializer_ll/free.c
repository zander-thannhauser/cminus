
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_initializer_ll(
	struct initializer_ll* this)
{
	tfree(this->head);
	tfree(this->tail);
}

