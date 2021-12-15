
#include "../struct.h"

struct function_type
{
	struct type super;
	struct type* return_type;
	struct parameter_ll* parameters;
};

