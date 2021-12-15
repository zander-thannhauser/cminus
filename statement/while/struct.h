
#include "../struct.h"

struct while_statement
{
	struct statement super;
	struct expression* conditional;
	struct statement* body;
};

