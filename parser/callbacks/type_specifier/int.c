
#include <assert.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "int.h"

struct type* type_specifier_int_callback(struct types* types)
{
	return tinc(types->integers[ik_signed_int]);
}

