
#ifdef VERBOSE_ASSEMBLY

#include <stdarg.h>
#include <stdlib.h>

#include <debug.h>

#include <memory/tmalloc.h>
/*#include <memory/tstrdup.h>*/
#include <memory/tinc.h>
#include <memory/tfree.h>

/*#include <expression/print.h>*/

#include "vfprintf.h"
#include "struct.h"
#include "indent.h"

static void free_ilink(void* ptr)
{
	struct indent_link* link = ptr;
	
	dpv(link);
	dpvs(link->value);
	
	free(link->value);
}

int asm_writer_indent2(struct asm_writer* this, const char* fmt, ...)
{
	struct indent_link* link = NULL;
	int error = 0;
	FILE* stream = NULL;
	char* value = NULL;
	size_t size = 0;
	ENTER;
	
	va_list vargs;
	
	va_start(vargs, fmt);
	
	if (!(stream = open_memstream(&value, &size)))
	{
		TODO;
		error = 1;
	}
	
	if (!error)
		error = asm_writer_vfprintf(stream, fmt, vargs);
	
	dpvs(value);
	
	fflush(stream);
	fclose(stream);
	va_end(vargs);
	
	if (!error)
		error = tmalloc((void**) &link, sizeof(*link), free_ilink);
	
	if (!error)
	{
		link->value = value, value = NULL;
		
		link->prev = this->indent_tail;
		link->next = NULL;
		
		if (!this->indent_head)
			this->indent_head = tinc(link);
		
		if (this->indent_tail)
			this->indent_tail->next = tinc(link);
		
		tfree(this->indent_tail);
		this->indent_tail = tinc(link);
	}
	
	tfree(link);
	free(value);
	
	EXIT;
	return error;
}














#endif
