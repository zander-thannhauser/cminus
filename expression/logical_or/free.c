
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_logical_or_expression(struct expression* super)
{
	struct logical_or_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->left), tfree(this->right);
	
	EXIT;
}

