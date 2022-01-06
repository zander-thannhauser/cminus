
struct yylloc;
struct variable_expression;
struct variable;

int new_variable_expression(
	struct variable_expression** new,
	struct yylloc* loc,
	struct variable* variable);




