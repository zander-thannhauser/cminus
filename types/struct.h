
#ifdef X64_TARGET
#include <type/integer/kind.h>
#include <type/float/kind.h>
#endif

struct types
{
	#ifdef X64_TARGET
	struct type* integers[number_of_integer_kinds];
	struct type* floats[number_of_float_kinds];
	#else
	struct type* int_type;
	struct type* float_type;
	#endif
	struct type* void_type;
	struct type* charptr_type;
};

