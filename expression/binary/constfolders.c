
#if 0
#include <debug.h>

#include <types/struct.h>

#include <type/primitive/kind.h>

#include <expression/literal/struct.h>
#include <expression/literal/new.h>

#include "constfolders.h"

#define N (number_of_binary_expressions)

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
	case (pk_##type): { \
		type x = l->value._##type, y = r->value._##type; \
		dpv(x); dpv(y); \
		error = new_literal_expression_as_##type(\
			(struct expression**) out, \
			types->primitives[pk_##type], (operation)); \
		break; \
	}

#define B(o) \
	C(signed_char, o)  C(unsigned_char, o) \
	C(signed_short, o) C(unsigned_short, o) \
	C(signed_int, o)   C(unsigned_int, o) \
	C(signed_long, o)  C(unsigned_long, o) \
	
/*	C(float, o)        C(double, o)*/

#define A(funcname, operation)\
	static int funcname(exp** out, exp* l, exp* r, struct types* types) { \
		int error = 0; \
		switch (l->kind) { \
			B(operation) \
			default: TODO; \
		}\
		return error; \
	}

A(fold_add, (x + y));
A(fold_subtract, (x - y));
A(fold_multiply, (x * y));
A(fold_divide, (x / y));

int (*binary_constfolders[N])(exp**, exp*, exp*, struct types*) = {
	[bek_add] = fold_add,
	[bek_subtract] = fold_subtract,
	[bek_multiply] = fold_multiply,
	[bek_divide] = fold_divide,
};


















#endif
