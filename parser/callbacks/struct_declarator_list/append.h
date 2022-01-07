
struct struct_declarator_ll;
struct struct_declarator;

int struct_declarator_list_append_callback(
	struct struct_declarator_ll** out,
	struct struct_declarator_ll* list,
	struct struct_declarator* element);
