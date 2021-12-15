
#include "../struct.h"

struct function_declarator
{
	struct declarator super;
	struct declarator* inner;
	struct parameter_ll* parameters;
};

