
#include <debug.h>

#include <memory/tmalloc.h>
#include <memory/tinc.h>
#include <memory/tfree.h>

#include <avl/tmalloc_tree.h>

#include "compare/variable.h"
#include "compare/type.h"

/*#include "free/variable.h"*/
/*#include "free/type.h"*/

#include "struct.h"
#include "new.h"
#include "free.h"

int new_scope(
	struct scope** new)
{
	int error = 0;
	ENTER;
	
	struct avl_tree_t* variables = NULL;
	struct avl_tree_t* types = NULL;
	struct avl_tree_t* structs = NULL;
/*	struct avl_tree_t* enums = NULL;*/
	
	struct scope* this = NULL;
	
	error = 0
		?: avl_tmalloc_tree(&variables, compare_variable, tfree)
		?: avl_tmalloc_tree(&types, compare_namedtype, tfree)
		?: avl_tmalloc_tree(&structs, compare_namedtype, tfree)
		?: tmalloc((void**) &this, sizeof(*this), (void (*)(void *)) free_scope);
	
	if (!error)
	{
		this->global.variables = tinc(variables);
		this->global.types = tinc(types);
		this->global.structs = tinc(structs);
		this->global.enums = NULL;
		
		this->stackhead = NULL;
		
		this->frame_size = 0;
		
		*new = this;
	}
	
	tfree(variables);
	tfree(types);
	tfree(structs);
	
	EXIT;
	return error;
}











