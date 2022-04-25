
#include <assert.h>

#include <memory/tfree.h>

#include <expression/struct.h>

#include "struct.h"
#include "free.h"

void free_expression_statement(struct statement* super)
{
	struct expression_statement* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->expression);
	
	EXIT;
}

