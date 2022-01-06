
#ifdef VERBOSE_ASSEMBLY

#include <stdarg.h>

#include <debug.h>

#include "struct.h"
#include "vfprintf.h"
#include "comment.h"

int asm_writer_comment(struct asm_writer* this, const char* fmt, ...)
{
	int error = 0;
/*	unsigned i, n;*/
	va_list args;
	ENTER;
	
	va_start(args, fmt);
	
	fprintf(this->stream, "\e[37m/* ");
	
	if (this->indent_head)
	{
		struct indent_link* link;
		for (link = this->indent_head; link; link = link->next)
		{
			fprintf(this->stream, "%s ", link->value);
			
			if (link->next)
				fprintf(this->stream, "| ");
		}
		
	}
	
/*	fprintf(this->stream, ":  ");*/
	
	asm_writer_vfprintf(this->stream, fmt, args);
	
	fprintf(this->stream, " */\e[0m\n");
	
	va_end(args);
	
	EXIT;
	return error;
}





#endif
