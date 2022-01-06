
struct compound_statement;
struct statement_ll;
struct yylloc;

int new_compound_statement(
	struct compound_statement** new,
	struct yylloc* loc,
	struct statement_ll* statements);
