
enum type_qualifier;
struct declaration_specifiers;

#include <enums/type_qualifier.h>

int declaration_specifiers_set_qualifier(
	struct declaration_specifiers* this,
	enum type_qualifier qualifier);
