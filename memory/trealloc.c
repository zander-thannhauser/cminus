
/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/*#include <errno.h>*/
/*#include <string.h>*/

/*#include <error.h>*/
/*#include <debug.h>*/

/*#include <defines/argv0.h>*/

/*#include "trealloc.h"*/

/*int trealloc(void** retval, size_t size)*/
/*{*/
/*	int error = 0;*/
/*	void* old = *retval, *new;*/
/*	ENTER;*/
/*	*/
/*	dpv(old);*/
/*	dpv(size);*/
/*	*/
/*	if (old)*/
/*		error = tmalloc(retval, size, NULL);*/
/*	if (!(new = realloc(old, size)) && size)*/
/*		fprintf(stderr, "%s: realloc(%lu): %s\n", argv0, size, strerror(errno)),*/
/*		error = e_out_of_memory;*/
/*	else*/
/*		*retval = new;*/
/*	*/
/*	TODO;*/
/*	*/
/*	EXIT;*/
/*	return error;*/
/*}*/

