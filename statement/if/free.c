
#include <debug.h>

#include <memory/tfree.h>

#include <expression/struct.h>

#include "struct.h"
#include "free.h"

void free_if_statement(struct statement* super)
{
	struct if_statement* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->conditional);
	tfree(this->true_case);
	tfree(this->false_case);
	
	EXIT;
}

