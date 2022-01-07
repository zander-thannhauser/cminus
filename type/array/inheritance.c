
#include "../inheritance.h"

#include "inheritance.h"
#include "print.h"
#include "free.h"

struct type_inheritance array_type_inheritance = {
	.print = array_type_print,
	.free = free_array_type,
};

