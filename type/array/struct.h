
#include "../struct.h"

struct array_type
{
	struct type super;
	struct type* element_type;
	size_t number_of_elements;
};

