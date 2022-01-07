
#include "../struct.h"

struct field_access_expression
{
	struct expression super;
	
	struct expression* inner;
	
	struct struct_field* field;
};

