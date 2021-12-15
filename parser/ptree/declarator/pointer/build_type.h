
struct type;
struct declarator;

int pointer_declarator_inheritance_build_type(
	char** out_identifier,
	struct type** out_type,
	struct type* base_type,
	struct declarator* super);
