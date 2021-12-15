
#include <string.h>
#include <stdlib.h>

#include <char/printable.h>

#include <debug.h>

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/

/*#include "../print.h"*/

#include "struct.h"
#include "print.h"

void string_expression_print(
	struct expression* super,
	FILE* stream)
{
	struct string_expression* const this = (typeof(this)) super;
	ENTER;
	
	putc('\"', stream);
	
	char* start = this->data, *end = start + this->strlen;
	
	for (; start < end; start++)
		if (index(printable, *start))
			putc(*start, stream);
		else switch (*start) {
			case '\n': fputs("\\n", stream); break;
			case '\t': fputs("\\t", stream); break;
			case '\'': fputs("\\'", stream); break;
			case '\"': fputs("\\\"", stream); break;
			default: fprintf(stream, "0x%02hhX", *start); break;
		}
	
	putc('\"', stream);
	
	EXIT;
}



















