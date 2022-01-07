
#include "../struct.h"

struct array_index_expression
{
	struct expression super;
	
	struct expression* array;
	struct expression* index; // ik_signed_long
};

