
#ifndef STRUCT_STATEMENT_H
#define STRUCT_STATEMENT_H

#include "kind.h"

struct statement
{
	enum statement_kind kind;
	struct statement_inheritance* inheritance;
	
	unsigned first_line, first_column;
	unsigned  last_line,  last_column;
};

#endif
