
#include "../struct.h"

#include "kind.h"

struct float_type
{
	struct type super;
	
	#ifdef X64_TARGET
	enum float_kind kind;
	#endif
};

