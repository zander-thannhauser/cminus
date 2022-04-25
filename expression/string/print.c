
#include <string.h>
#include <stdlib.h>

#include <char/printable.h>

#include <assert.h>

/*#include <type/integer/struct.h>*/
/*#include <type/float/struct.h>*/

/*#include "../print.h"*/

#include <misc/sfprintf.h>

#include "struct.h"
#include "print.h"

int string_expression_print(
	struct expression* super,
	FILE* stream)
{
	int error = 0;
	struct string_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = sfprintf(stream, "\"");
	
	char* start = this->data, *end = start + this->strlen - 1;
	
	for (; !error && start < end; start++)
		if (*start && index(printable, *start))
			error = sfprintf(stream, "%c", *start);
		else switch (*start) {
			case '\n': error = sfprintf(stream, "%s", "\\n"); break;
			case '\t': error = sfprintf(stream, "%s", "\\t"); break;
			case '\0': error = sfprintf(stream, "%s", "\\0"); break;
			case '\'': error = sfprintf(stream, "%s", "\'"); break;
			case '\"': error = sfprintf(stream, "%s", "\""); break;
			default: error = sfprintf(stream, "0x%02hhX", *start); break;
		}
	
	if (!error)
		error = sfprintf(stream, "\"");
	
	EXIT;
	return error;
}



















