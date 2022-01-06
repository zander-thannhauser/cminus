
#include "../inheritance.h"

#include "inheritance.h"
#include "compare.h"
#include "print.h"
#include "free.h"

struct type_inheritance pointer_type_inheritance = {
	.compare = compare_pointer_types,
	.print = pointer_type_print,
	.free = free_pointer_type,
};

