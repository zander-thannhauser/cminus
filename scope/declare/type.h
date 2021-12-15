
struct scope;
struct type;

int scope_declare_type(
	struct scope* this,
	char* identifier,
	struct type* type);
