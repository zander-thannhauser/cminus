
#include <debug.h>

#include <memory/tfree.h>

#include <expression/struct.h>

#include "struct.h"
#include "free.h"

void free_expression_statement(struct statement* super)
{
	struct expression_statement* this = (typeof(this)) super;
	ENTER;
	
	dpv(super->kind);
	dpv(this->expression);
	dpv(this->expression->kind);
	
	tfree(this->expression);
	
	EXIT;
}

