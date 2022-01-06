
#include <debug.h>

#include <parser/parameter/struct.h>
#include <parser/parameter_ll/struct.h>

#include "../compare.h"

#include "struct.h"
#include "compare.h"

int compare_function_types(
	const struct type* _a,
	const struct type* _b)
{
	int cmp = 0;
	const struct function_type* a = (typeof(a)) _a;
	const struct function_type* b = (typeof(b)) _b;
	struct parameter_link* a_link, *b_link;
	struct parameter *ap, *bp;
	ENTER;
	
	cmp = compare_types(a->return_type, b->return_type);
	
	for (a_link = a->parameters->head, b_link = b->parameters->head;
		!cmp && a_link && b_link;
		a_link = a_link->next, b_link = b_link->next)
	{
		ap = a_link->element, bp = b_link->element;
		
		cmp = compare_types(ap->type, bp->type);
	}
	
	if (cmp);
	else if (!!a_link > !!b_link)
		cmp = +1;
	else if (!!a_link < !!b_link)
		cmp = -1;
	else if (a->parameters->ellipsis > b->parameters->ellipsis)
		cmp = +1;
	else if (a->parameters->ellipsis < b->parameters->ellipsis)
		cmp = -1;
	
	dpv(cmp);
	
	EXIT;
	return cmp;
}










