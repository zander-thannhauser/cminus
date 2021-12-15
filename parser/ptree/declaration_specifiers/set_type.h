
struct declaration_specifiers;
struct types;
struct type;

int declaration_specifiers_set_type(
	struct declaration_specifiers* this,
	struct type* type,
	struct types* types);
