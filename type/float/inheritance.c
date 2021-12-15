
#include "../inheritance.h"

#include "free.h"
#include "clone_with_qualifiers.h"
#include "is_equal.h"
#include "inheritance.h"

struct type_inheritance float_type_inheritance = {
	.clone_with_qualifiers = float_type_clone_with_qualifiers,
	.is_equal = float_type_is_equal,
	.free = free_float_type
};

