
struct specifier_qualifiers;
struct type;

int specifier_qualifier_list_prepend_specifier(
	struct specifier_qualifiers** out,
	struct type* type_specifier,
	struct specifier_qualifiers* inner,
	struct types* types);
