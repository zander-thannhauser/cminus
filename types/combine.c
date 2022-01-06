
#include <debug.h>

/*#include <macros/max.h>*/

#include <memory/tinc.h>
/*#include <memory/tfree.h>*/

#include <type/integer/struct.h>

#include "struct.h"
#include "combine.h"

static const enum integer_kind
lookup[number_of_integer_kinds][number_of_integer_kinds] = 
{
	[ik_signed_int][ik_signed_char]      = ik_signed_char,
	[ik_signed_int][ik_signed_short]     = ik_signed_short,
	[ik_signed_int][ik_signed_int]       = ik_signed_int,
	[ik_signed_int][ik_signed_long]      = ik_signed_long,
	[ik_signed_int][ik_unsigned_char]    = ik_unsigned_char,
	[ik_signed_int][ik_unsigned_short]   = ik_unsigned_short,
	[ik_signed_int][ik_unsigned_int]     = ik_unsigned_int,
	[ik_signed_int][ik_unsigned_long]    = ik_unsigned_long,
	
	[ik_signed_char]   [ik_signed_int]   = ik_signed_char,
	[ik_signed_short]  [ik_signed_int]   = ik_signed_short,
	[ik_signed_int]    [ik_signed_int]   = ik_signed_int,
	[ik_signed_long]   [ik_signed_int]   = ik_signed_long,
	[ik_unsigned_char] [ik_signed_int]   = ik_unsigned_char,
	[ik_unsigned_short][ik_signed_int]   = ik_unsigned_short,
	[ik_unsigned_int]  [ik_signed_int]   = ik_unsigned_int,
	[ik_unsigned_long] [ik_signed_int]   = ik_unsigned_long,
	
	[ik_signed_char]   [ik_unsigned_int] = ik_unsigned_char,
	[ik_signed_short]  [ik_unsigned_int] = ik_unsigned_short,
	[ik_signed_int]    [ik_unsigned_int] = ik_unsigned_int,
	[ik_signed_long]   [ik_unsigned_int] = ik_unsigned_long,
	
	[ik_unsigned_int][ik_signed_char]    = ik_unsigned_char,
	[ik_unsigned_int][ik_signed_short]   = ik_unsigned_short,
	[ik_unsigned_int][ik_signed_int]     = ik_unsigned_int,
	[ik_unsigned_int][ik_signed_long]    = ik_unsigned_long,
	[ik_unsigned_int][ik_unsigned_char]  = ik_unsigned_char,
	[ik_unsigned_int][ik_unsigned_short] = ik_unsigned_short,
	[ik_unsigned_int][ik_unsigned_int]   = ik_unsigned_int,
	[ik_unsigned_int][ik_unsigned_long]  = ik_unsigned_long,
	
};

int types_combine(
	struct type** out,
	struct types* types,
	struct type* a, struct type* b)
{
	int error = 0;
	ENTER;
	
	if (a->kind == tk_integer && b->kind == tk_integer)
	{
		struct integer_type *A = (typeof(A)) a, *B = (typeof(B)) b;
		enum integer_kind ak = A->kind, bk = B->kind, resultant_kind;
		
		dpv(ak);
		dpv(bk);
		
		resultant_kind = lookup[ak][bk];
		
		*out = tinc(types->integers[resultant_kind]);
	}
	else
	{
		dpv(a->kind);
		dpv(b->kind);
		
		TODO;
		error = 1;
	}
	
	EXIT;
	return error;
}

















