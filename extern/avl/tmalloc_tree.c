
#include <assert.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "avl.h"

#include "tmalloc_tree.h"

int avl_tmalloc_tree(
	struct avl_tree_t** new,
	avl_compare_t cmp,
	avl_freeitem_t freeitem)
{
	int error = 0;
	struct avl_tree_t* this = NULL;
	ENTER;
	
	error = tmalloc(
		(void**) &this, sizeof(*this),
		(void (*)(void*)) avl_free_nodes);
	
	if (!error)
	{
		avl_init_tree(this, cmp, freeitem);
		
		*new = tinc(this);
	}
	
	tfree(this);
	
	EXIT;
	return error;
}


