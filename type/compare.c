
#include <assert.h>

#include "struct.h"
#include "inheritance.h"
#include "compare.h"

int compare_types(
	const struct type* a,
	const struct type* b)
{
	int cmp = 0;
	ENTER;
	
	dpv(a);
	dpv(b);
	
	if (a != b)
	{
		int i, n;
		
		dpv(a->kind);
		dpv(b->kind);
		
		if (a->kind > b->kind)
			cmp = +1;
		else if (a->kind < b->kind)
			cmp = -1;
		else
		{
			assert(a->inheritance->compare);
			
			cmp = a->inheritance->compare(a, b);
		}
		
		for (i = 0, n = number_of_type_qualifiers; !cmp && i < n; i++)
			if (a->qualifiers[i] > b->qualifiers[i])
				cmp = 1;
			else if (a->qualifiers[i] < b->qualifiers[i])
				cmp = -1;
				
		dpv(cmp);
	}
	
	EXIT;
	return cmp;
}




















