
#ifndef EXPRESSION_STRUCT_H
#define EXPRESSION_STRUCT_H

#include "kind.h"

struct expression
{
	enum expression_kind kind;
	
	struct expression_inheritance* inheritance;
	
	struct type* type;
};

#endif
