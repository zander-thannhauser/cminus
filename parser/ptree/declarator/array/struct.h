
#include <stdbool.h>
#include <stddef.h>

#include "../struct.h"

struct array_declarator
{
	struct declarator super;
	struct declarator* inner;
	
	bool sizeless;
	size_t array_size;
};

