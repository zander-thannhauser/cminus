
#ifndef integer_KIND_H
#define integer_KIND_H

// order defines type promotion
// and coercsion, do not change!

// unsigned is odd, signed is even

enum integer_kind
{
	ik_signed_char,
	ik_unsigned_char,
	
	ik_signed_short,
	ik_unsigned_short,
	
	ik_signed_int,
	ik_unsigned_int,
	
	ik_signed_long,
	ik_unsigned_long,
	
	number_of_integer_kinds,
};

#define ik_bool (ik_signed_int)
#define pk__Bool (ik_signed_int)

#endif
