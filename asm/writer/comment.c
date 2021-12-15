
#include <stdarg.h>

#include <debug.h>

#include "struct.h"
#include "vfprintf.h"
#include "comment.h"

int asm_writer_comment(struct asm_writer* this, const char* fmt, ...)
{
	int error = 0;
	unsigned i, n;
	va_list args;
	ENTER;
	
	va_start(args, fmt);
	
	for (i = 0, n = this->indent; !error && i < n; i++)
		fputc(' ', this->out);
	
	dpvs(fmt);
	
	fprintf(this->out, "# ");
	asm_writer_vfprintf(this, fmt, args);
	fputc('\n', this->out);
	
	va_end(args);
	
	EXIT;
	return error;
}

