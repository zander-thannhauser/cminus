
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_bitshift_expression(struct expression* super)
{
	struct bitshift_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->left), tfree(this->right);
	
	EXIT;
}

