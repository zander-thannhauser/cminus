
#include <debug.h>

#include "field/struct.h"
#include "field_ll/struct.h"

#include "../compare.h"

#include "struct.h"
#include "compare.h"

int compare_struct_types(
	const struct type* _a,
	const struct type* _b)
{
	int cmp = 0;
	const struct struct_type* a = (typeof(a)) _a;
	const struct struct_type* b = (typeof(b)) _b;
	ENTER;
	
	dpv(a);
	dpv(b);
	
	dpv(a->fields);
	dpv(b->fields);
	
	assert(a);
	assert(b);
	
	assert(a->fields);
	assert(b->fields);
	
	struct struct_field_ll_link *all, *bll;
	
	if (a->struct_or_union > b->struct_or_union)
		cmp = 1;
	else if (a->struct_or_union < b->struct_or_union)
		cmp = -1;
	
	for (all = a->fields->head, bll = b->fields->head;
		!cmp && all && bll;
		all = all->next, bll = bll->next)
	{
		cmp = compare_types(all->element->type, bll->element->type);
	}
	
	if (cmp);
	else if (!!all > !!bll)
		cmp = 1;
	else if (!!all < !!bll)
		cmp = -1;
	
	EXIT;
	return cmp;
}


































