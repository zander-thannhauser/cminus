
#include <assert.h>

#include <memory/tfree.h>
#include <memory/tinc.h>

/*#include <parser/translation_unit_ll/merge.h>*/

#include "append.h"

int translation_unit_append_callback(
	struct translation_unit_ll** out,
	struct translation_unit_ll* this,
	struct translation_unit_ll* that)
{
	int error = 0;
	ENTER;
	
	#if 0
	translation_unit_ll_merge(this, that);
	
	*out = tinc(this);
	
	tfree(this);
	tfree(that);
	#endif
	
	EXIT;
	return error;
}

