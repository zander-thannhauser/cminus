
#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/parameter_ll/struct.h>

#include "ellipsis.h"

void parameter_type_list_ellipsis(
	struct parameter_ll** out,
	struct parameter_ll* in)
{
	ENTER;
	
	dpv(in);
	
/*	CHECK;*/
	
	in->ellipsis = true;
	
	*out = tinc(in);
	
	tfree(in);
	
	EXIT;
}

