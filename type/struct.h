
#ifndef TYPE_STRUCT
#define TYPE_STRUCT

#include <stdbool.h>

#include <stdbool.h>
#include <stddef.h>

#include <enums/storage_class.h>
#include <enums/type_qualifier.h>

#include "kind.h"

struct type
{
	enum type_kind kind;
	struct type_inheritance* inheritance;
	
	bool is_complete;
	
	bool qualifiers[number_of_type_qualifiers];
	
	size_t size;
};

#endif
