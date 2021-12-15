
struct statement;
struct asm_writer;

struct statement_inheritance
{
	int (*write_asm)(struct statement*, struct asm_writer*);
	void (*free)(struct statement*);
};

