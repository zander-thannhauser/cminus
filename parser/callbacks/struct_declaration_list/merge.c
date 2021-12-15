
#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct/field_ll/merge.h>

#include "merge.h"

int struct_declaration_list_merge_callback(
	struct struct_field_ll** out,
	struct struct_field_ll* first,
	struct struct_field_ll* second)
{
	int error = 0;
	ENTER;
	
	struct_field_ll_merge(first, second);
	
	*out = tinc(first);
	
	tfree(first), tfree(second);
	
	EXIT;
	return error;
}

