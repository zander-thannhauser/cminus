
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <parser/ptree/type_qualifiers/new.h>
#include <parser/ptree/type_qualifiers/mark_qualifier.h>

#include "head.h"

int type_qualifier_list_head_callback(
	struct type_qualifiers** retval,
	enum type_qualifier type_qualifier)
{
	int error = 0;
	struct type_qualifiers* qualifiers = NULL;
	ENTER;
	
	error = new_type_qualifiers(&qualifiers);
	
	if (!error)
		type_qualifiers_mark_qualifier(qualifiers, type_qualifier);
	
	if (!error)
		*retval = tinc(qualifiers);
	
	tfree(qualifiers);
	
	EXIT;
	return error;
}
