
struct compound_statement;
struct statement_ll;

int new_compound_statement(
	struct compound_statement** new,
	unsigned line,
	struct statement_ll* statements);
