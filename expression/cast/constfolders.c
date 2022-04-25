
#if 0
#include <assert.h>

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

#define C(type, cast_to) \
	case (pk_##type): { \
		error = new_literal_expression_as_##cast_to( \
			(struct expression**) out, \
			types->primitives[pk_##cast_to], (cast_to) in->value._##type); \
		break; \
	}

#define B(o) \
	C(bool, o) \
	C(signed_char, o)  C(unsigned_char, o) \
	C(signed_short, o) C(unsigned_short, o) \
	C(signed_int, o)   C(unsigned_int, o) \
	C(signed_long, o)  C(unsigned_long, o) \


/*	C(float, o)        C(double, o)*/

#define A(cast_to)\
	static int fold_##cast_to(exp** out, exp* in, struct types* types) { \
		int error = 0; \
		switch (in->kind) { \
			B(cast_to) \
			default: TODO; \
		}\
		return error; \
	}

A(bool);

A(signed_char);
A(unsigned_char);

A(signed_short);
A(unsigned_short);

A(signed_int);
A(unsigned_int);

A(signed_long);
A(unsigned_long);

/*A(float);*/
/*A(double);*/

int (*cast_constfolders[number_of_primitive_types])(exp**, exp*, struct types*) = {
	[pk_bool] = fold_bool,
	
	[pk_signed_char] = fold_signed_char,
	[pk_unsigned_char] = fold_unsigned_char,
	
	[pk_signed_short] = fold_signed_short,
	[pk_unsigned_short] = fold_unsigned_short,
	
	[pk_signed_int] = fold_signed_int,
	[pk_unsigned_int] = fold_unsigned_int,
	
	[pk_signed_long] = fold_signed_long,
	[pk_unsigned_long] = fold_unsigned_long,
	
/*	[pk_float] = fold_float,*/
/*	[pk_double] = fold_double,*/
};
















#endif
