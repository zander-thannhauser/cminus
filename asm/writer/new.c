
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <enums/error.h>
#include <debug.h>

#include <defines/argv0.h>

#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_asm_writer(struct asm_writer** new, const char* path)
{
	int error = 0;
	FILE* stream = NULL;
	struct asm_writer* this = NULL;
	ENTER;
	
	if (!(stream = fopen(path, "w")))
		fprintf(stderr, "%s: fopen(\"%s\", \"w\") failed: %m\n", argv0, path),
		error = e_syscall_failed;
	
	if (!error)
		error = tmalloc((void**) &this, sizeof(*this),
			(void (*)(void*)) free_asm_writer);
	
	if (!error)
	{
		this->stream = stream, stream = NULL;
		
		#ifdef VERBOSE_ASSEMBLY
		this->indent_head = NULL;
		this->indent_tail = NULL;
		#endif
		
		*new = this;
	}
	
	if (stream)
		fclose(stream);
	
	EXIT;
	return error;
}















