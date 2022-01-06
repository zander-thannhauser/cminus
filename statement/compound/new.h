
struct compound_statement;
struct statement_ll;

int new_compound_statement(
	struct compound_statement** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct statement_ll* statements);
