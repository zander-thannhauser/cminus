
struct type;
struct declarator;

int function_declarator_inheritance_build_type(
	char** out_identifier,
	struct type** out_type,
	struct type* base_type,
	struct declarator* super);
