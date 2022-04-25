
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_field_access_expression(struct expression* super)
{
	struct field_access_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->field);
	
	EXIT;
}

