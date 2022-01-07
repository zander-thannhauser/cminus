
#include "../inheritance.h"

#include "free.h"
#include "print.h"
#include "compare.h"
#include "inheritance.h"

struct type_inheritance struct_type_inheritance = {
	.print = struct_type_print,
	.compare = compare_struct_types,
	.free = free_struct_type
};

