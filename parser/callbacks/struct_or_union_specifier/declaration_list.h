
struct type;
struct struct_field_ll;

int struct_or_union_specifier_declaration_list_callback(
	struct type** out,
	bool struct_or_union,
	char* identifier,
	struct struct_field_ll* fields,
	struct scope* scope);
