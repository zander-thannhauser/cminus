
enum type_qualifier;
struct declaration_specifiers;

#include <enums/type_qualifier.h>

int declaration_specifiers_type_qualifier_callback(
	struct declaration_specifiers** out,
	enum type_qualifier type_qualifier,
	struct declaration_specifiers* inner);
