
struct expression_statement;
struct expression;
struct yylloc;

int new_expression_statement(
	struct expression_statement** new,
	struct yylloc* loc,
	struct expression* expression);











