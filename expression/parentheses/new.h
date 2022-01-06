
struct yylloc;
struct expression;

int new_parentheses_expression(
	struct expression** new,
	struct yylloc* loc,
	struct expression* inner);
