
struct specifier_qualifiers;
struct types;
struct type;

int specifier_qualifiers_set_type(
	struct specifier_qualifiers* this,
	struct type* type,
	struct types* types);
