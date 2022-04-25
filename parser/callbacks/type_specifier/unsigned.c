
#include <assert.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "unsigned.h"

struct type* type_specifier_unsigned_callback(struct types* types)
{
	return tinc(types->integers[ik_unsigned_int]);
}

