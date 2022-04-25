
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_comma_expression(struct expression* super)
{
	struct comma_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->left), tfree(this->right);
	
	EXIT;
}

