
#include <stddef.h>

struct initializer;
struct type;
struct expression;
struct integer_type;
struct float_type;
struct struct_type;
struct pointer_type;

int initializer_traverse(
	struct initializer* this,
	struct type* type,
	int (*on_zero)(size_t),
	int (*on_integer)(struct integer_type*, struct expression**),
	int (*on_float)(struct float_type*, struct expression**),
	int (*on_pointer)(struct pointer_type*, struct expression**),
	int (*on_struct)(struct struct_type*, struct expression**),
	int (*ef)(struct type*, const char*),
	int (*xf)(struct type* t),
	int (*ei)(unsigned long),
	int (*xi)(unsigned long));
