
#ifndef EXPRESSION_STRUCT_H
#define EXPRESSION_STRUCT_H

#include "kind.h"

struct expression
{
	enum expression_kind kind;
	
	struct expression_inheritance* inheritance;
	
	unsigned first_line, first_column;
	unsigned  last_line,  last_column;
	
	struct type* type;
};

#endif
