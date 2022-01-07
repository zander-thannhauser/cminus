
#include <stdio.h>

#include <debug.h>

#include <avl/avl.h>

#include <memory/tinc.h>

#include "../struct.h"
#include "../namedtype.h"

#include "type.h"

struct type* scope_lookup_type(
	struct scope* this,
	const char* name)
{
	struct type* retval = NULL;
	struct avl_node_t* node;
	struct layer* i;
	struct namedtype* namedtype;
	ENTER;
	
	for (i = this->stackhead; !retval && i; i = i->prev)
	{
		if ((node = avl_search(i->local.types, &name)))
		{
			namedtype = node->item;
			retval = tinc(namedtype->type);
		}
	}
	
	if (!retval && (node = avl_search(this->global.types, &name)))
	{
		namedtype = node->item;
		retval = tinc(namedtype->type);
	}
	
	EXIT;
	return retval;
}















