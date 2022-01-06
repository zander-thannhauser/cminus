
#include <stdlib.h>

#include <debug.h>

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

/*#include <type/struct.h>*/
/*#include <type/is_equal.h>*/

/*#include <types/struct.h>*/

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_comma_expression(
	struct expression** new,
	struct expression* left,
	struct expression* right,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	struct comma_expression* this = NULL;
		
	error = new_expression(
		(struct expression**) &this,
		ek_binary, &comma_expression_inheritance,
		right->type, sizeof(*this));
	
	if (!error)
	{
		this->left = tinc(left);
		this->right = tinc(right);
		
		*new = (struct expression*) this;
	}
	#endif
	
	EXIT;
	return error;
}












