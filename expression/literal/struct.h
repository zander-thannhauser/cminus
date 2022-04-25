
#include <stdbool.h>
#include <stddef.h>

#include <type/integer/kind.h>

#include "../struct.h"

struct literal_expression
{
	struct expression super;
	
	union {
		
		#ifdef X64_TARGET
		signed char _signed_char;
		signed short _signed_short;
		#endif
		signed int _signed_int;
		
		#ifdef X64_TARGET
		signed long _signed_long;
		
		unsigned char _unsigned_char;
		unsigned short _unsigned_short;
		unsigned int _unsigned_int;
		unsigned long _unsigned_long;
		#endif
		
		float _float;
		
		#ifdef X64_TARGET
		double _double;
		#endif
	} value;
};













