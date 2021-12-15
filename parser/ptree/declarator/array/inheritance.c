
#include "../inheritance.h"

#include "free.h"
#include "build_type.h"
#include "inheritance.h"

struct declarator_inheritance array_declarator_inheritance = {
	.build_type = array_declarator_inheritance_build_type,
	.free = free_array_declarator,
};

