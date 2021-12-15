
#include "../struct.h"

struct identifier_declarator
{
	struct declarator super;
	
	char* identifier; // might be null (abstract declarator)
};

