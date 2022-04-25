
#include <assert.h>

#include <memory/tfree.h>

#include <parser/ptree/declarator/identifier/new.h>

#include "identifier.h"

int direct_declarator_identifier_callback(
	struct declarator** new,
	char* identifier)
{
	int error = 0;
	ENTER;
	
	dpvs(identifier);
	assert(identifier);
	
	error = new_identifier_declarator(
		(struct identifier_declarator**) new,
		identifier);
	
	tfree(identifier);
	
	EXIT;
	return error;
}

