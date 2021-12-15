
enum type_qualifier;
struct pointer;
struct type_qualifiers;

int new_pointer(
	struct pointer** new,
	struct type_qualifiers* qualifiers,
	struct pointer* inner);
