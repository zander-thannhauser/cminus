
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>

#include <avl/avl.h>

#include "../struct.h"

#include "variable.h"

struct variable* scope_lookup_variable(
	struct scope* this,
	const char* name)
{
	struct variable* retval = NULL;
	struct layer* i;
	struct avl_node_t* node;
	ENTER;
	
	for (i = this->stackhead; !retval && i; i = i->prev)
		if ((node = avl_search(i->local.variables, &name)))
			retval = tinc(node->item);
	
	if (!retval && (node = avl_search(this->global.variables, &name)))
		retval = tinc(node->item);
	
	EXIT;
	return retval;
}

