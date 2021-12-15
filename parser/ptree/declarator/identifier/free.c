
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_identifier_declarator(
	struct declarator* super)
{
	struct identifier_declarator* this = (typeof(this)) super;
	ENTER;
	
	tfree(this->identifier);
	
	EXIT;
}

