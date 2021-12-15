
struct compound_statement;
struct statement_ll;
struct statement_ll;

int compound_statement_statements_callback(
	struct compound_statement** retval,
	unsigned line,
	struct statement_ll* declarations,
	struct statement_ll* statements);
