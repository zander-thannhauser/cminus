
#include "../inheritance.h"

#include "free.h"
#include "clone_with_qualifiers.h"
#include "compare.h"
#include "inheritance.h"
#include "print.h"

struct type_inheritance float_type_inheritance = {
	.clone_with_qualifiers = float_type_clone_with_qualifiers,
	.compare = compare_float_types,
	.free = free_float_type,
	.print = float_type_print,
};

