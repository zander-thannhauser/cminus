
#include <stdbool.h>
#include <stddef.h>

#include <type/integer/kind.h>

#include "../struct.h"

struct literal_expression
{
	struct expression super;
	
	union {
		signed char _signed_char;
		signed short _signed_short;
		signed int _signed_int;
		signed long _signed_long;
		
		unsigned char _unsigned_char;
		unsigned short _unsigned_short;
		unsigned int _unsigned_int;
		unsigned long _unsigned_long;
		
		float _float;
		double _double;
	} value;
};













