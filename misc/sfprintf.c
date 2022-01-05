
#include <stdarg.h>
#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include "sfprintf.h"

int sfprintf(FILE* stream, const char* fmt, ...)
{
	int error = 0;
	ENTER;
	
	va_list vargs;
	
	va_start(vargs, fmt);
	
	if (vfprintf(stream, fmt, vargs) < 0)
	{
		fprintf(stderr, "%s: vfprintf(): %m\n", argv0);
		error = e_syscall_failed;
	}
	
	va_end(vargs);
	
	EXIT;
	return error;
}

