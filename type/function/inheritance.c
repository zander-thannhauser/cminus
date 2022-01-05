
#include "../inheritance.h"

#include "free.h"
#include "is_equal.h"
#include "print.h"

#include "inheritance.h"

struct type_inheritance function_type_inheritance = {
	.is_equal = function_type_is_equal,
	.free = free_function_type,
	.print = function_type_print,
};

