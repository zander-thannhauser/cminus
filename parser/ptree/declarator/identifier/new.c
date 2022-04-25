
#include <assert.h>

#include <memory/tinc.h>

#include "../kind.h"
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_identifier_declarator(
	struct identifier_declarator** new,
	char* identifier)
{
	int error = 0;
	ENTER;
	
	// `identifier` is optional, because abstract declarators don't have
	// names
	
	struct identifier_declarator* this = NULL;
	
	error = new_declarator(
		(struct declarator**) &this,
		pdk_identifier,
		&identifier_declarator_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->identifier = tinc(identifier);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

