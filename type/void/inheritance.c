
#include "../inheritance.h"

#include "inheritance.h"
#include "print.h"
#include "free.h"

struct type_inheritance void_type_inheritance = {
	.print = void_type_print,
	.free = free_void_type,
};

