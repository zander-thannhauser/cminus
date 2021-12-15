
struct type;
struct declaration_specifiers;

int declaration_specifiers_type_specifier_callback(
	struct declaration_specifiers** out,
	struct type* type_specifier,
	struct declaration_specifiers* specifiers,
	struct types* types);
