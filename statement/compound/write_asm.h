
struct compound_statement;
struct asm_writer;
struct statement;

int compound_statement_write_asm(struct compound_statement* this, struct asm_writer* writer);

int inheritance_compound_statement_write_asm(
	struct statement* super, struct asm_writer* writer);
