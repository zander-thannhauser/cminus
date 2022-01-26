
#include <sys/wait.h>
#include <stdio.h>

#include <debug.h>
#include <enums/error.h>

#include <defines/argv0.h>

#include <macros/str.h>

#include <memory/tfree.h>

#include <cmdln/flags.h>
#include <cmdln/process.h>
#include <cmdln/free.h>

#include <asm/writer/new.h>

#include <scope/new.h>

#include <types/new.h>
#include <types/free.h>

#include <parser/scanner.h>
#include <parser/parser.h>

#include <misc/mypopen.h>

#ifdef DEBUGGING
int debug_depth;
#endif

int main(int argc, char* const* argv)
{
	int error = 0;
	struct cmdln_flags* flags = NULL;
	FILE *fin = NULL;
	pid_t preprocessor = -1;
	struct scope *scope = NULL;
	struct types* types = NULL;
	struct asm_writer* asm_writer = NULL;
	char* file = NULL;
	size_t section_counter = 0;
	ENTER;
	
	error = 0
		// process command-line flags:
		?: process_cmdln(&flags, argc, argv)
		// allocate primitive types:
		?: new_types(&types)
		// allocate scopes, push global scope:
		?: new_scope(&scope)
		// try to output input file:
		?: new_asm_writer(&asm_writer, flags->output_path);
	
	// try to open input file:
	if (!error)
	{
		if (flags->preprocess)
			error = mypopen(&fin, &preprocessor,
				"cpp",
				"-D", "__attribute__(...)=",
				"-D", "__asm__(...)=",
				"-D", "__builtin_va_list=int",
				"-D", "__restrict=",
				"-D", "TARGET=" str(TARGET),
				flags->input_path, NULL);
		else if (!(fin = fopen(flags->input_path, "r")))
			fprintf(stderr, "%s: fopen(\"%s\"): %m\n", argv0, flags->input_path),
			error = e_bad_input_file;
	}
	
	if (!error)
	{
		// pass `fin` to flex:
		yyin = fin;
		
		// invoke parser:
		yyparse(&error, scope, types, asm_writer, &file, &section_counter);
	}
	
	tfree(asm_writer);
	
	// deallocate scopes:
	tfree(scope);
	
	// deallocate types:
	tfree(types);
	
	// shutdown flex:
	yylex_destroy();
	if (fin) fclose(fin);
	tfree(file);
	
	int wstatus = 0;
	if (preprocessor > 0)
	{
		if (waitpid(preprocessor, &wstatus, 0) < 0)
		{
			fprintf(stderr, "%s: waitpid(): %m\n", argv0),
			error = e_syscall_failed;
		}
		else if (wstatus)
		{
			fprintf(stderr, "%s: C preprocessor exit()-ed with a nonzero "
				"value!\n", argv0);
			error = e_subcommand_failed;
		}
	}
	
	// free cmdln flags:
	tfree(flags);
	
	EXIT;
	return error;
}










