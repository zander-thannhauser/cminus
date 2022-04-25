
#include <stdio.h>

#include <assert.h>

/*#include <memory/tinc.h>*/
#include <memory/tfree.h>

/*#include <parser/ptree/pointer/struct.h>*/

#include <parser/ptree/declarator/pointer/new_from_pointer.h>

#include "pointer.h"

int declarator_pointer_callback(
	struct declarator** out,
	struct pointer* pointer,
	struct declarator* inner)
{
	int error = 0;
	ENTER;
	
	error = new_pointer_declarator_from_pointer(out, pointer, inner);
	
	tfree(pointer), tfree(inner);
	
	EXIT;
	return error;
}





