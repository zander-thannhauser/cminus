
struct scope;
struct expression;

int primary_expression_identifier_callback(
	struct expression** retval,
	struct scope* scope,
	char* identifier);
