
#include <debug.h>

/*#include <type/is_equal.h>*/

#include <parser/parameter/struct.h>
#include <parser/parameter_ll/struct.h>

#include "struct.h"
#include "compare.h"

int compare_function_types(
	const struct type* _a,
	const struct type* _b)
{
	bool retval = true;
	const struct function_type* a = (typeof(a)) _a;
	const struct function_type* b = (typeof(b)) _b;
	ENTER;
	
	TODO;
	#if 0
	if (retval && !type_is_equal(a->return_type, b->return_type))
		retval = false;
	
	struct parameter_link* a_link, *b_link;
	struct parameter *ap, *bp;
	
	for (a_link = a->parameters->head, b_link = b->parameters->head;
		retval && a_link && b_link;
		a_link = a_link->next, b_link = b_link->next)
	{
		ap = a_link->element, bp = b_link->element;
		
		if (!type_is_equal(ap->type, bp->type))
			retval = false;
	}
	
	if (retval && !a_link != !b_link)
		retval = false;
	
	if (retval && a->parameters->ellipsis != b->parameters->ellipsis)
		retval = false;
	
	dpvb(retval);
	#endif
	
	EXIT;
	return retval;
}










