
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>

#include <parser/ptree/struct_declarator/new.h>

#include "declarator.h"

int struct_declarator_declarator(
	struct struct_declarator** out,
	struct declarator* declarator)
{
	int error = 0;
	ENTER;
	
	error = new_struct_declarator(out, declarator, NULL);
	
	tfree(declarator);
	
	EXIT;
	return error;
}

