
struct statement;
struct expression;
struct yylloc;

int new_expression_statement(
	struct statement** new,
	struct yylloc* loc,
	struct expression* expression);











