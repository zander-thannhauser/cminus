
#include <stdio.h>
#include <stdbool.h>

struct expression;
struct asm_writer;

struct expression_inheritance
{
	int (*write_rasm)(struct expression*, struct asm_writer*);
	int (*write_lasm)(struct expression*, struct asm_writer*);
	
	int (*print)(struct expression*, FILE* stream);
	
	void (*free)(struct expression*);
};

