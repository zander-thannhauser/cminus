
struct scope;
struct type;

int scope_declare_struct(
	struct scope* this,
	char* identifier,
	struct type* type);
