
#include <debug.h>

#include <memory/tinc.h>

#include <types/struct.h>

#include "double.h"

struct type* type_specifier_double_callback(struct types* types)
{
	return (struct type*) tinc(types->floats[fk_double]);
}

