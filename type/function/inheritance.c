
#include "../inheritance.h"

#include "free.h"
#include "compare.h"
#include "print.h"

#include "inheritance.h"

struct type_inheritance function_type_inheritance = {
	.compare = compare_function_types,
	.free = free_function_type,
	.print = function_type_print,
};

