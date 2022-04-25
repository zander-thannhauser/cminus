
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_initializer_expression(struct expression* super)
{
	struct initializer_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->initializer);
	
	EXIT;
}

