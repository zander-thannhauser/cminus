
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_binary_expression(struct expression* super)
{
	struct binary_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->left), tfree(this->right);
	
	EXIT;
}

