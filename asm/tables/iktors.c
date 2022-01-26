

#ifdef X64_TARGET

#include "iktors.h"

const enum register_size iktors[number_of_integer_kinds] =
{
	[ik_signed_char] = byte,
	[ik_unsigned_char] = byte,
	[ik_signed_short] = word,
	[ik_unsigned_short] = word,
	[ik_signed_int] = doubleword,
	[ik_unsigned_int] = doubleword,
	[ik_signed_long] = quadword,
	[ik_unsigned_long] = quadword,
};

#endif
