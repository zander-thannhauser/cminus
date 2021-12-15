
#include "kind.h"

struct declarator
{
	enum declarator_kind kind;
	struct declarator_inheritance* inheritance;
};

