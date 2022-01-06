
#include <stdarg.h>
#include <debug.h>

#include "struct.h"
#include "vfprintf.h"
#include "write.h"

int asm_writer_write(struct asm_writer* this, const char* fmt, ...)
{
	int error = 0;
/*	unsigned i, n;*/
	va_list args;
	ENTER;
	
	va_start(args, fmt);
	
	#ifdef VERBOSE_ASSEMBLY
	if (this->indent_head)
	{
		fprintf(this->stream, "\e[37m/* ");
		
		struct indent_link* link;
		for (link = this->indent_head; link; link = link->next)
		{
			fprintf(this->stream, "%s ", link->value);
			
			if (link->next)
				fprintf(this->stream, "| ");
		}
		
		fprintf(this->stream, "*/\e[0m ");
	}
	#endif
	
	asm_writer_vfprintf(this->stream, fmt, args);
	
	fputc('\n', this->stream);
	
	va_end(args);
	
	EXIT;
	return error;
}

