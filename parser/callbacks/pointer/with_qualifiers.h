
struct pointer;
struct type_qualifiers;

int pointer_with_qualifiers_callback(
	struct pointer** out,
	struct type_qualifiers* type_qualifiers,
	struct pointer* prev);
