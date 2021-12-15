
#include <debug.h>

#include <memory/tfree.h>

/*#include <expression/struct.h>*/

#include "struct.h"
#include "free.h"

void free_while_statement(struct statement* super)
{
	struct while_statement* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->conditional);
	tfree(this->body);
	
	EXIT;
}

