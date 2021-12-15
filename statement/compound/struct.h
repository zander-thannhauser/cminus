
#include "../struct.h"

struct compound_statement
{
	struct statement super;
	
	struct statement_ll* statements;
};
