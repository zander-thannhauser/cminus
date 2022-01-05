
#include <stdio.h>

struct asm_writer
{
	FILE* stream;
	
	#ifdef VERBOSE_ASSEMBLY
	struct indent_link {
		char* value;
		struct indent_link* next, *prev;
	}* indent_head, *indent_tail;
	#endif
};

