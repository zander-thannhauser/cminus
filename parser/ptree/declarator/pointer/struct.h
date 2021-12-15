
#include "../struct.h"

struct pointer_declarator
{
	struct declarator super;
	
	struct type_qualifiers* qualifiers;
	
	struct declarator* inner;
};

