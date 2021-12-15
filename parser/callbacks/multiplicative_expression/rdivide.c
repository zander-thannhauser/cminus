
#include <debug.h>

#include <memory/tfree.h>

#include <expression/binary/new.h>

#include "rdivide.h"

int multiplicative_expression_rdivide_callback(
	struct expression** retval,
	struct expression* left,
	struct expression* right)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	error = new_binary_expression(
		(struct binary_expression**) retval,
		bek_rdivide,
		left, right);
	#endif
	
	tfree(left), tfree(right);
	
	EXIT;
	return error;
}

