
#include <debug.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "short.h"

struct type* type_specifier_short_callback(struct types* types)
{
	return tinc(types->integers[ik_signed_short]);
}

