
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_logical_and_expression(struct expression* super)
{
	struct logical_and_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->left), tfree(this->right);
	
	EXIT;
}

