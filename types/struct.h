
#include <type/integer/kind.h>
#include <type/float/kind.h>

struct types
{
	struct type* integers[number_of_integer_kinds];
	struct type* floats[number_of_float_kinds];
	struct type* void_type;
	struct type* charptr_type;
};

