
#include <assert.h>

#include <macros/N.h>

#include <memory/tinc.h>

#include "struct.h"
#include "inheritance.h"
#include "clone_with_qualifiers.h"

#ifdef DEBUGGING
static const char* lookup[] = {
	[tq_constant] = "constant",
	[tq_volatile] = "volatile",
};
#endif

int type_clone_with_qualifiers(
	struct type** outgoing,
	struct type* this,
	bool qualifiers[number_of_type_qualifiers])
{
	int error = 0;
	ENTER;
	
	dpv(this);
	assert(this);
	
	int i, n;
	bool all_qualifiers_met = true;
	// do we already have all qualifiers met?
	for (i = 0, n = N(this->qualifiers); all_qualifiers_met && i < n; i++)
		if (this->qualifiers[i] < qualifiers[i])
		{
			#ifdef DEBUGGING
			ddprintf("missing '%s' qualifier!\n", lookup[i]);
			#endif
			all_qualifiers_met = false;
		}
	
	dpvb(all_qualifiers_met);
	
	// if so:
	if (all_qualifiers_met)
	{
		HERE;
		*outgoing = tinc(this);
	}
	else
	{
		dpv(this);
		dpv(this->kind);
		error = (this->inheritance->clone_with_qualifiers)(outgoing, this, qualifiers);
	}
	
	EXIT;
	return error;
}














