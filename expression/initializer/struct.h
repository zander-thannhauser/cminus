
#include <stddef.h>

#include "../struct.h"

struct initializer_expression
{
	struct expression super;
	
	size_t stack_offset;
	
	struct initializer* initializer;
};

