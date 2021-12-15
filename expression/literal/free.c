
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_literal_expression(struct expression* super)
{
	struct literal_expression* this = (typeof(this)) super;
	ENTER;
	
	EXIT;
}

