
struct type;
struct scope;

int struct_or_union_specifier_just_identifier_callback(
	struct type** outgoing,
	bool struct_or_union,
	char* identifier,
	struct scope* scope);
