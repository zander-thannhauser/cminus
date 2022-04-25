
#include <assert.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free_link.h"

void free_declaration_link(struct declaration_link* link)
{
	ENTER;
	
	tfree(link->element);
	tfree(link->next);
	
	EXIT;
}

