
#ifdef X64_TARGET
#include "fktors.h"

const enum register_size fktors[number_of_float_kinds] =
{
	[fk_float] = doubleword,
	[fk_double] = quadword,
};
#endif
