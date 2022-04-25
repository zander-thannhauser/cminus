
#include <assert.h>

#include <avl/tmalloc_tree.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include "compare/variable.h"
#include "compare/type.h"

#include "free/variable.h"
#include "free/type.h"
#include "free/layer.h"

#include "struct.h"
#include "push.h"

int scope_push(struct scope* this)
{
	int error = 0;
	ENTER;
	
	struct avl_tree_t* variables = NULL;
	struct avl_tree_t* types = NULL;
	struct avl_tree_t* structs = NULL;
/*	struct avl_tree_t* enums = NULL;*/
	
	struct layer* new = NULL;
	
	if (!this->stackhead)
		this->frame_size = 0;
	
	error = 0
		?: avl_tmalloc_tree(&variables, compare_variable, tfree)
		?: avl_tmalloc_tree(&types, compare_namedtype, tfree)
		?: avl_tmalloc_tree(&structs, compare_namedtype, tfree)
		?: tmalloc((void*) &new, sizeof(*new), free_layer);
	
	if (!error)
	{
		new->offset = this->stackhead ? this->stackhead->offset : 0;
		
		new->local.variables = tinc(variables);
		new->local.types = tinc(types);
		new->local.structs = tinc(structs);
		new->local.enums = NULL;
		
		new->prev = this->stackhead;
		
		this->stackhead = new;
	}
	
	tfree(variables);
	tfree(types);
	tfree(structs);
	
	EXIT;
	return error;
}
















