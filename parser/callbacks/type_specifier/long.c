
#include <assert.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "long.h"

struct type* type_specifier_long_callback(struct types* types)
{
	return tinc(types->integers[ik_signed_long]);
}

