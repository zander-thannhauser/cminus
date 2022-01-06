
#include <stdio.h>

#include <debug.h>
#include <enums/error.h>

#include <defines/argv0.h>

#include <memory/tfree.h>

#include <cmdln/flags.h>
#include <cmdln/process.h>
#include <cmdln/free.h>

#include <scope/new.h>

#include <types/new.h>
#include <types/free.h>

#include <asm/writer/new.h>

#include <parser/scanner.h>
#include <parser/parser.h>

#ifdef DEBUGGING
int debug_depth;
#endif

int main(int argc, char* const* argv)
{
	int error = 0;
	struct cmdln_flags* flags = NULL;
	FILE *fin = NULL, *fout = NULL;
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
	if (!error && !(fin = fopen(flags->input_path, "r")))
		fprintf(stderr, "%s: fopen(\"%s\"): %m\n", argv0, flags->input_path),
		error = e_bad_input_file;
	
	if (!error)
	{
		// pass `fin` to flex:
		yyin = fin;
		
		// invoke parser:
		yyparse(&error, scope, types, asm_writer, &file, &section_counter);
	}
	
	if (error)
	{
		CHECK;
	}
	
	tfree(asm_writer);
	
	// deallocate scopes:
	tfree(scope);
	
	// deallocate types:
	tfree(types);
	
	// shutdown flex:
	yylex_destroy();
	if (fin) fclose(fin);
	if (fout) fclose(fout);
	
	tfree(file);
	
	// free cmdln flags:
	tfree(flags);
	
	EXIT;
	return error;
}










