
struct types;
struct specifier_qualifiers;
struct type;

int specifier_qualifier_list_head_specifier(
	struct specifier_qualifiers** out,
	struct type* type,
	struct types* types);
