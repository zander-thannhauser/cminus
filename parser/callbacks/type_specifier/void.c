
#include <assert.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "void.h"

struct type* type_specifier_void_callback(struct types* types)
{
	return tinc(types->void_type);
}

