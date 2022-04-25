
#include "../struct.h"

#include "kind.h"
/*#include "integer_kind.h"*/

struct integer_type
{
	struct type super;
	
	#ifdef X64_TARGET
	enum integer_kind kind;
	#endif
};

