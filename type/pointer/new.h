
#include <stdbool.h>

struct pointer_type;
struct type;
struct expression;

#include <enums/type_qualifier.h>

int new_pointer_type(
	struct pointer_type** new,
	bool qualifiers[number_of_type_qualifiers],
	struct type* inner);
