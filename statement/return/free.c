
#include <assert.h>

#include <memory/tfree.h>

#include <expression/struct.h>

#include "struct.h"
#include "free.h"

void free_return_statement(struct statement* super)
{
	struct return_statement* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->return_value);
	
	EXIT;
}

