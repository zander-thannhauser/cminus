
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_expression_ll(
	struct expression_ll* this)
{
	tfree(this->head);
	tfree(this->tail);
}

