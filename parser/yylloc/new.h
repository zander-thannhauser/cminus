
struct yylloc;

int new_yyloc(
	struct yylloc** new,
	unsigned first_line, unsigned first_column,
	unsigned last_line, unsigned last_column);
