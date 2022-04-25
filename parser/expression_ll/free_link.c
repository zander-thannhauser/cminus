
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_expression_link(
	struct expression_link* this)
{
	ENTER;
	tfree(this->element);
	tfree(this->next);
	EXIT;
}

