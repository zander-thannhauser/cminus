
#include <stdbool.h>

#include <enums/type_qualifier.h>

struct type;
struct type_qualifiers;

int type_clone_with_qualifiers(
	struct type** outgoing,
	struct type* this,
	bool qualifiers[number_of_type_qualifiers]);
