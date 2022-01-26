
#if 0
#include <debug.h>

#include <type/integer/struct.h>
/*#include <type/float/struct.h>*/

#include <types/struct.h>

#include <expression/literal/struct.h>
#include <expression/literal/new.h>

#include "constfolders.h"

#define N (number_of_arithmetic_expressions)

typedef struct literal_expression exp;

typedef   signed char    signed_char;
typedef   signed short   signed_short;
typedef   signed int     signed_int;
typedef   signed long    signed_long;
typedef unsigned char  unsigned_char;
typedef unsigned short unsigned_short;
typedef unsigned int   unsigned_int;
typedef unsigned long  unsigned_long;

#define C(type, operation) \
	case (ik_##type): { \
		type x = l->value._##type, y = r->value._##type; \
		dpv(x); dpv(y); \
		error = new_literal_expression_as_##type(\
			(struct expression**) out, loc, \
			types->integers[ik_##type], (operation)); \
		break; \
	}

#define B(o) \
	C(signed_char, o)  C(unsigned_char, o) \
	C(signed_short, o) C(unsigned_short, o) \
	C(signed_int, o)   C(unsigned_int, o) \
	C(signed_long, o)  C(unsigned_long, o) \
	
#define A(funcname, operation) \
	static int funcname( \
		exp** out, exp* l, exp* r, \
		struct yylloc* loc, \
		struct types* types) \
	{ \
		int error = 0; \
		switch (((struct integer_type*) l->super.type)->kind) { \
			B(operation) \
			default: TODO; \
		}\
		return error; \
	}

A(fold_add, (x + y));
A(fold_subtract, (x - y));
A(fold_multiply, (x * y));
A(fold_divide, (x / y));
A(fold_rdivide, (x % y));

int (*arithmetic_constfolders[N])(
	exp**, exp*, exp*,
	struct yylloc*,
	struct types*) =
{
	[aek_add] = fold_add,
	[aek_subtract] = fold_subtract,
	[aek_multiply] = fold_multiply,
	[aek_divide] = fold_divide,
	[aek_rdivide] = fold_rdivide,
};

















#endif
