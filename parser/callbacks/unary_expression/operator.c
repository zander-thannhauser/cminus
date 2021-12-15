
#include <debug.h>

#include <memory/tfree.h>

#include <type/struct.h>

#include <expression/struct.h>
#include <expression/unary/new.h>

#include "operator.h"

int unary_expression_operator(
	struct expression** out,
	enum unary_expression_kind kind,
	struct expression* inner,
	struct types* types)
{
	int error = 0;
	ENTER;
	
	// no implied casts:
	
	dpv(inner->type->kind);
/*	CHECK;*/
	
	error = new_unary_expression(
		(struct expression**) out, kind, inner, types);
	
	tfree(inner);
	
	EXIT;
	return error;
}

