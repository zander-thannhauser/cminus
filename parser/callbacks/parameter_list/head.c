
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/parameter_ll/new.h>
#include <parser/parameter_ll/append.h>

#include "head.h"

int parameter_list_head_callback(
	struct parameter_ll** out,
	struct parameter* head)
{
	int error = 0;
	struct parameter_ll* pll = NULL;
	ENTER;
	
	error = 0
		?: new_parameter_ll(&pll)
		?: parameter_ll_append(pll, head) ;
	
	if (!error)
		*out = tinc(pll);
	
	tfree(pll);
	tfree(head);
	
	EXIT;
	return error;
}

