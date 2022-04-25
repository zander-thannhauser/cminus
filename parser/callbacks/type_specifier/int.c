
#include <debug.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "int.h"

struct type* type_specifier_int_callback(struct types* types)
{
	#ifdef X64_TARGET
	return tinc(types->integers[ik_signed_int]);
	#else
	return tinc(types->int_type);
	#endif
}

