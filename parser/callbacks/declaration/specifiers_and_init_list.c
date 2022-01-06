
#include <stdbool.h>
#include <stdio.h>

#include <debug.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <type/struct.h>
#include <type/clone_with_qualifiers.h>

#include <scope/variable.h>
#include <scope/declare/type.h>
#include <scope/declare/variable.h>

/*#include <parser/declaration/new.h>*/
#include <parser/statement_ll/new.h>
#include <parser/statement_ll/append.h>

#include <parser/ptree/type_qualifiers/struct.h>
#include <parser/ptree/declarator/build_type.h>
#include <parser/ptree/declaration_specifiers/struct.h>
#include <parser/ptree/init_declarator/struct.h>
#include <parser/ptree/init_declarator_ll/struct.h>

#include "specifiers_and_init_list.h"

int declaration_specifiers_and_init_list_callback(
	struct statement_ll** retval,
	struct declaration_specifiers* specifiers,
	struct init_declarator_ll* init_list,
	struct scope* scope)
{
	int error = 0;
	struct statement_ll* statements = NULL;
	struct type* base_type = NULL;
	bool is_typedef;
	ENTER;
	
	// "not only could I be building types,
	// not only could I be declaring variables,
	// I could also be allocating assignment statements.
	// if fact, that's the only part I really remember"
	
	// shortcuts:
	is_typedef = (specifiers->storage_class == sc_typedef);
	
	dpv(specifiers->type);
	
	error = 0
		?: type_clone_with_qualifiers(&base_type, specifiers->type, specifiers->qualifiers->qualifiers)
		?: new_statement_ll(&statements);
	
	struct init_declarator_ll_link* link;
	for (link = init_list->head; !error && link; link = link->next)
	{
		struct statement* statement = NULL;
		char* identifier = NULL;
		struct type* type = NULL;
		struct init_declarator* init = link->element;
		
		error = declarator_build_type(
			&identifier, &type,
			base_type, init->declarator);
		
		if (!error)
		{
			if (is_typedef)
			{
				if (init->initializer)
				{
					error = 1;
				}
				else
					error = scope_declare_type(scope, identifier, type);
			}
			else
			{
				struct variable* variable = NULL;
				
				error = scope_declare_variable(scope,
					identifier, type, specifiers->storage_class, &variable);
				
				if (!error)
				{
					if (!variable->is_global)
					{
						if (init->initializer)
						{
							// curly brackets lead to
							// many sub-assignments
							// and possibly casts
							// new_expression_statement();
							
							// statement_ll_append();
							TODO;
						}
					}
					else if (true
						&& specifiers->storage_class != sc_extern
						&& type->kind != tk_function)
					{
						TODO;
						#if 0
						if (init->initializer)
						{
							TODO;
						}
						else
						{
							TODO;
						}
						
						int asm_writer_write_global(
							struct asm_writer* writer,
							const char* name,
							bool is_static,
							void* value,
							size_t size);
						#endif
						TODO;
					}
				}
				
				
				tfree(variable);
			}
		}
		
		tfree(statement);
		tfree(identifier);
		tfree(type);
	}
	
	if (!error)
		*retval = tinc(statements);
	
	tfree(specifiers);
	tfree(init_list);
	
	tfree(base_type);
	tfree(statements);
	
	
	EXIT;
	return error;
}













