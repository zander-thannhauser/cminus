
#include <enums/type_qualifier.h>

struct type;
struct type_qualifiers;

int float_type_clone_with_qualifiers(
	struct type** outgoing,
	const struct type* this,
	bool qualifiers[number_of_type_qualifiers]);
