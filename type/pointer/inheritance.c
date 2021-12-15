
#include "../inheritance.h"

#include "inheritance.h"
#include "is_equal.h"
#include "print.h"
#include "free.h"

struct type_inheritance pointer_type_inheritance = {
	.is_equal = pointer_type_is_equal,
	.print = pointer_type_print,
	.free = free_pointer_type,
};

