
struct scope;
struct declarator;
struct function_type;
struct declaration_specifiers;
struct function_definition;

int function_definition_prebody(
	struct function_definition** out,
	struct declaration_specifiers* specifiers,
	struct declarator* declarator,
	struct scope* scope);
