
#include <debug.h>

#include <memory/tinc.h>

#include "../kind.h"
#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_pointer_declarator(
	struct pointer_declarator** new,
	struct type_qualifiers* qualifiers,
	struct declarator* inner)
{
	int error = 0;
	ENTER;
	
	struct pointer_declarator* this = NULL;
	
	error = new_declarator(
		(struct declarator**) &this,
		pdk_pointer,
		&pointer_declarator_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->inner = tinc(inner);
		this->qualifiers = tinc(qualifiers);
		
		*new = this;
	}
	
	EXIT;
	return error;
}









