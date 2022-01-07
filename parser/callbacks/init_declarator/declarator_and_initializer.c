
#include <debug.h>

#include <memory/tfree.h>

#include <parser/ptree/init_declarator/new.h>

#include "declarator_and_initializer.h"

int init_declarator_declarator_and_initializer_callback(
	struct init_declarator** out,
	struct declarator* declarator,
	struct initializer* initializer)
{
	int error = 0;
	ENTER;
	
	error = new_init_declarator(out, declarator, initializer);
	
	tfree(declarator), tfree(initializer);
	
	EXIT;
	return error;
}

