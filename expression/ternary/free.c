
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_ternary_expression(struct expression* super)
{
	struct ternary_expression* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->conditional);
	tfree(this->true_expression);
	tfree(this->false_expression);
	
	EXIT;
}

