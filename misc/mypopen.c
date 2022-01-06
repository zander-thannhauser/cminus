
#include <debug.h>

#include <enums/error.h>

#include <memory/trealloc.h>
#include <memory/tfree.h>

#include "mypopen.h"

int mypopen(
	FILE** out_file,
	pid_t* out_pid,
	char* argv0, ...)
{
	int error = 0;
	FILE* file = NULL;
	pid_t child = -1;
	int wstatus;
	int pfds[2] = {-1, -1};
	va_list vargs;
	struct {
		char** data;
		size_t n, cap;
	} argv = {};
	ENTER;
	
	va_start(vargs, argv0);
	
	for (char* pushme = argv0; ; (pushme = va_arg(vargs, char*)) )
	{
		dpvs(pushme);
		
		if (argv.n + 1 >= argv.cap)
		{
			argv.cap = argv.cap * 2 ?: 1;
			error = trealloc((void**) &argv.data, argv.cap * sizeof(*argv.data));
		}
		
		if (!error)
			argv.data[argv.n++] = pushme;
		
		if (!pushme)
			break;
	}
	
	va_end(vargs);
	
	if (error);
	else if (pipe2(pfds, O_CLOEXEC) < 0)
		fprintf(stderr, "%s: pipe2(): %m\n", argv0),
		error = e_syscall_failed;
	else if ((child = fork()) < 0)
		fprintf(stderr, "%s: fork(): %m\n", argv0),
		error = e_syscall_failed;
	else if (child)
	{
		if ((file = fdopen(pfds[0], "r")))
		{
			pfds[0] = -1;
		}
		else
		{
			fprintf(stderr, "%s: fdopen(): %m\n", argv0),
			error = e_syscall_failed;
		}
	}
	else if (dup2(pfds[1], 1) < 0)
		fprintf(stderr, "%s: dup2(): %m\n", argv0),
		error = e_syscall_failed;
	else if (execvp(argv.data[0], argv.data) < 0)
		fprintf(stderr, "%s: execvp(): %m\n", argv0),
		error = e_syscall_failed;
	
	if (!error)
	{
		*out_file = file, file = NULL;
		*out_pid = child, child = -1;
	}
	
	if (child > 0) waitpid(child, &wstatus, 0);
	
	if (pfds[0] > 0) close(pfds[0]);
	if (pfds[1] > 0) close(pfds[1]);
	
	if (file) fclose(file);
	
	tfree(argv.data);
	
	EXIT;
	return error;
}











