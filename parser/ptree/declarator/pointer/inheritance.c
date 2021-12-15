
#include "../inheritance.h"

#include "free.h"
#include "build_type.h"
#include "inheritance.h"

struct declarator_inheritance pointer_declarator_inheritance = {
	.build_type = pointer_declarator_inheritance_build_type,
	.free = free_pointer_declarator,
};

