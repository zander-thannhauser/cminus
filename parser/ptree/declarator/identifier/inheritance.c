
#include "../inheritance.h"

#include "free.h"
#include "build_type.h"
#include "inheritance.h"

struct declarator_inheritance identifier_declarator_inheritance = {
	.build_type = identifier_declarator_inheritance_build_type,
	.free = free_identifier_declarator,
};

