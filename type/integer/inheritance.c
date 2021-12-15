
#include "../inheritance.h"

#include "free.h"
#include "clone_with_qualifiers.h"
#include "is_equal.h"
#include "print.h"
#include "inheritance.h"

struct type_inheritance integer_type_inheritance = {
	.clone_with_qualifiers = integer_type_clone_with_qualifiers,
	.is_equal = integer_type_is_equal,
	.print = integer_type_print,
	.free = free_integer_type
};

