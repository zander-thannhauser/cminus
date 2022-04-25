

#include <stddef.h>

#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_initializer_as_expression(
	struct initializer** out,
	struct yylloc* loc,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	struct initializer* this = NULL;
	
	error = tmalloc((void**) &this, sizeof(*this), free_initializer);
	
	if (!error)
	{
		this->kind = ik_expression;
		this->loc = tinc(loc);
		this->expression = tinc(expression);
		
		*out = this;
	}
	
	EXIT;
	return error;
}

int new_initializer_as_initializer_ll(
	struct initializer** out,
	struct yylloc* loc,
	struct initializer_ll* initializer_ll)
{
	int error = 0;
	ENTER;
	
	struct initializer* this = NULL;
	
	error = tmalloc((void**) &this, sizeof(*this), free_initializer);
	
	if (!error)
	{
		this->kind = ik_initializer_list;
		this->loc = tinc(loc);
		this->initializer_ll = tinc(initializer_ll);
		
		*out = this;
	}
	
	EXIT;
	return error;
}























