
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_relational_expression(struct expression* super)
{
	struct relational_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->left), tfree(this->right);
	
	EXIT;
}

