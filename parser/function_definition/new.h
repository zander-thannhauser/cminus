
struct function_definition;
struct function_type;
struct compound_statement;
struct variable_ll;

int new_function_definition(
	struct function_definition** new,
	char* name,
	struct function_type* ftype,
	enum storage_class storage_class,
	struct variable_ll* parameters);
