
struct parameter;
struct declaration_specifiers;
struct declarator;

int parameter_declaration_declarator_callback(
	struct parameter** out,
	struct declaration_specifiers* specifiers,
	struct declarator* declarator);
