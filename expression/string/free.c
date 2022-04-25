
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_string_expression(struct expression* super)
{
	struct string_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->data);
	
	EXIT;
}

