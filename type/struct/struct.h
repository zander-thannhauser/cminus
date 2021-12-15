
#include <stdbool.h>

struct struct_field_ll;

#include "../struct.h"

struct struct_type
{
	struct type super;
	
	bool struct_or_union; // true for struct, false for union
	
	struct struct_field_ll* fields;
};

