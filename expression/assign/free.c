
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_assign_expression(struct expression* super)
{
	struct assign_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->left), tfree(this->right);
	
	EXIT;
}

