
#include "../struct.h"

struct if_statement
{
	struct statement super;
	struct expression* conditional;
	struct statement* true_case;
	struct statement* false_case;
};

