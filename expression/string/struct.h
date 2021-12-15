
#include <stddef.h>

#include "../struct.h"

struct string_expression
{
	struct expression super;
	size_t string_id;
	
	char* data; size_t strlen;
};
