
#include <debug.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "float.h"

struct type* type_specifier_float_callback(struct types* types)
{
	return (struct type*) tinc(types->floats[fk_float]);
}

