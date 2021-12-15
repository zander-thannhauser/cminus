
#include "../inheritance.h"

#include "free.h"
#include "build_type.h"
#include "inheritance.h"

struct declarator_inheritance function_declarator_inheritance = {
	.build_type = function_declarator_inheritance_build_type,
	.free = free_function_declarator,
};

