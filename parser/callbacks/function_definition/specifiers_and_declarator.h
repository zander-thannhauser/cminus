
struct function_definition;
struct function_type;
struct compound_statement;

int function_definition_with_specifiers_and_declarator(
	struct function_definition** retval,
	struct function_definition* prebody_function_definition,
	struct compound_statement* function_body);
