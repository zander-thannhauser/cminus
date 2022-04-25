
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_arithmetic_expression(struct expression* super)
{
	struct arithmetic_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->left), tfree(this->right);
	
	EXIT;
}

