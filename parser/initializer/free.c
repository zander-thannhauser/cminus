

#include <debug.h>

#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_initializer(void* ptr)
{
	struct initializer* const this = ptr;
	ENTER;
	
	switch (this->kind)
	{
		case ik_expression:
			tfree(this->expression);
			break;
		
		case ik_initializer_list:
			tfree(this->initializer_ll);
			break;
	}
	
	EXIT;
}

