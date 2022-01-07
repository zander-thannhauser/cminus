
struct tscope;
struct declaration;
struct declaration_specifiers;
struct init_declarator_ll;
struct declaration_ll;
struct statement_ll;
struct scope;
struct asm_writer;

int declaration_specifiers_and_init_list_callback(
	struct statement_ll** retval,
	struct declaration_specifiers* specifiers,
	struct init_declarator_ll* init_list,
	struct scope* scope,
	struct asm_writer* writer);
