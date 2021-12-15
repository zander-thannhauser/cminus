
#include <debug.h>

#include <memory/tfree.h>
#include <memory/tinc.h>

#include <parser/statement_ll/merge.h>

#include "merge.h"

void declaration_list_merge_callback(
	struct statement_ll** out,
	struct statement_ll* first,
	struct statement_ll* second)
{
	ENTER;
	
	statement_ll_merge(first, second);
	
	*out = tinc(first);
	
	tfree(first);
	tfree(second);
	
	EXIT;
}

