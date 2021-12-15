
#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_declaration_specifiers(
	struct declaration_specifiers* this)
{
	ENTER;
	
	tfree(this->type);
	tfree(this->qualifiers);
	
	EXIT;
}

