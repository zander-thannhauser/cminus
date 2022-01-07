
#include <stdio.h>
#include <sys/types.h>

int mypopen(
	FILE** out_file,
	pid_t* out_pid,
	char* argv0, ...);
