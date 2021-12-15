
struct type;
struct declarator;

int declarator_build_type(
	char** out_identifier,
	struct type** out_type,
	struct type* base_type,
	struct declarator* this);
