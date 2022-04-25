
#include <assert.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "char.h"

struct type* type_specifier_char_callback(struct types* types)
{
	return tinc(types->integers[ik_signed_char]);
}

