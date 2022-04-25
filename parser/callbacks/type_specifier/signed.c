
#include <assert.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "signed.h"

struct type* type_specifier_signed_callback(struct types* types)
{
	return tinc(types->integers[ik_signed_int]);
}

