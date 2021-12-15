
#include <stdio.h>

#include <debug.h>

#include <memory/tfree.h>

#include <parser/ptree/init_declarator/new.h>

#include "just_declarator.h"

int init_declarator_just_declarator_callback(
	struct init_declarator** new,
	struct declarator* declarator)
{
	int error = 0;
	ENTER;
	
	error = new_init_declarator(new, declarator, NULL);
	
	tfree(declarator);
	
	EXIT;
	return error;
}

