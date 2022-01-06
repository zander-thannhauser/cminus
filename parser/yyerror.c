
#include <stdio.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include "yyerror.h"

int yyerror(
	int*  error,
	void* _,
	void* __,
	void* ___,
	void* ____,
	void* _____,
	const char* s)
{
	fprintf(stderr, "%s: bison: %s\n", argv0, s);
	
	*error = e_syntax_error;
	
	return 1;
}

