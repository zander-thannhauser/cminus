
#include <enums/type_qualifier.h>

struct pointer_declarator;
struct declarator;

int new_pointer_declarator(
	struct pointer_declarator** new,
	struct type_qualifiers* qualifiers,
	struct declarator* inner);
