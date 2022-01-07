
#ifndef ENUM_ERROR_H
#define ENUM_ERROR_H

enum error
{
	e_success,
	e_syscall_failed,
	e_bad_cmdline_args,
	e_out_of_memory,
	e_bad_input_file,
	e_subcommand_failed,
	e_syntax_error,
	
	// internal errors:
	e_malformed_format_string,
};

#endif
