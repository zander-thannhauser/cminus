
#include <debug.h>

#include <macros/max.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct.h>
/*#include <type/primitive/struct.h>*/

#include "struct.h"
#include "combine.h"

#if 0
static enum primitive_kind
lookup[number_of_primitive_types][number_of_primitive_types] = 
{
	[pk_signed_int][pk_signed_char]      = pk_signed_char,
	[pk_signed_int][pk_signed_short]     = pk_signed_short,
	[pk_signed_int][pk_signed_int]       = pk_signed_int,
	[pk_signed_int][pk_signed_long]      = pk_signed_long,
	[pk_signed_int][pk_unsigned_char]    = pk_unsigned_char,
	[pk_signed_int][pk_unsigned_short]   = pk_unsigned_short,
	[pk_signed_int][pk_unsigned_int]     = pk_unsigned_int,
	[pk_signed_int][pk_unsigned_long]    = pk_unsigned_long,
	
	[pk_signed_char]   [pk_signed_int]   = pk_signed_char,
	[pk_signed_short]  [pk_signed_int]   = pk_signed_short,
	[pk_signed_int]    [pk_signed_int]   = pk_signed_int,
	[pk_signed_long]   [pk_signed_int]   = pk_signed_long,
	[pk_unsigned_char] [pk_signed_int]   = pk_unsigned_char,
	[pk_unsigned_short][pk_signed_int]   = pk_unsigned_short,
	[pk_unsigned_int]  [pk_signed_int]   = pk_unsigned_int,
	[pk_unsigned_long] [pk_signed_int]   = pk_unsigned_long,
	
	[pk_signed_char]   [pk_unsigned_int] = pk_unsigned_char,
	[pk_signed_short]  [pk_unsigned_int] = pk_unsigned_short,
	[pk_signed_int]    [pk_unsigned_int] = pk_unsigned_int,
	[pk_signed_long]   [pk_unsigned_int] = pk_unsigned_long,
	
	[pk_unsigned_int][pk_signed_char]    = pk_unsigned_char,
	[pk_unsigned_int][pk_signed_short]   = pk_unsigned_short,
	[pk_unsigned_int][pk_signed_int]     = pk_unsigned_int,
	[pk_unsigned_int][pk_signed_long]    = pk_unsigned_long,
	[pk_unsigned_int][pk_unsigned_char]  = pk_unsigned_char,
	[pk_unsigned_int][pk_unsigned_short] = pk_unsigned_short,
	[pk_unsigned_int][pk_unsigned_int]   = pk_unsigned_int,
	[pk_unsigned_int][pk_unsigned_long]  = pk_unsigned_long,
	
};
#endif

int types_combine(
	struct type** out,
	struct types* types,
	struct type* a, struct type* b)
{
	int error = 0;
	ENTER;
	
	#if 0
	if (a->kind != tk_primitive || b->kind != tk_primitive)
	{
		TODO;
		error = 1;
	}
	else
	{
		struct primitive_type *A = (typeof(A)) a, *B = (typeof(B)) b;
		enum primitive_kind ak = A->kind, bk = B->kind, resultant_kind;
		
		dpv(ak);
		dpv(bk);
		
		resultant_kind = lookup[ak][bk];
		
		*out = tinc(types->primitives[resultant_kind]);
	}
	#endif
	
	EXIT;
	return error;
}

















