
struct types;
struct while_statement;
struct expression;
struct statement;
struct yylloc;

int new_while_statement(
	struct while_statement** new,
	struct yylloc* loc,
	struct expression* conditional,
	struct statement* body);



