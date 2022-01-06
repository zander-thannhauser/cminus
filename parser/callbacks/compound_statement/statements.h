
struct compound_statement;
struct statement_ll;
struct statement_ll;

int compound_statement_statements_callback(
	struct compound_statement** retval,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column,
	struct statement_ll* declarations,
	struct statement_ll* statements);
