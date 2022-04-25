
#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include <memory/tinc.h>
#include <memory/tfree.h>

#include <asm/writer/write/global.h>

#include <type/struct.h>
#include <type/clone_with_qualifiers.h>

#include <scope/variable.h>
#include <scope/declare/type.h>
#include <scope/declare/variable.h>

#include <expression/struct.h>
#include <expression/initializer/new.h>

#include <statement/expression/new.h>

/*#include <parser/declaration/new.h>*/
#include <parser/statement_ll/new.h>
#include <parser/statement_ll/append.h>

#include <parser/initializer/struct.h>
#include <parser/initializer/casted.h>

#include <parser/ptree/type_qualifiers/struct.h>
#include <parser/ptree/declarator/build_type.h>
#include <parser/ptree/declaration_specifiers/struct.h>
#include <parser/ptree/init_declarator/struct.h>
#include <parser/ptree/init_declarator_ll/struct.h>

#ifdef DEBUGGING
#include <parser/statement_ll/struct.h>
#endif

#include "specifiers_and_init_list.h"

int declaration_specifiers_and_init_list_callback(
	struct statement_ll** retval,
	struct declaration_specifiers* specifiers,
	struct init_declarator_ll* init_list,
	struct scope* scope,
	struct asm_writer* writer)
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
		// "also globals".
	
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
					TODO;
					error = 1;
				}
				
				if (!error)
					error = scope_declare_type(scope, identifier, type);
			}
			else
			{
				struct variable* variable = NULL;
				
				error = scope_declare_variable(scope,
					identifier, type, specifiers->storage_class, &variable);
				
				if (!error && init->initializer)
					error = cast_initializer(init->initializer, type);
				
				if (!error)
				{
					dpv(variable);
					
					if (!variable->is_global)
					{
						if (init->initializer)
						{
							struct expression* e = NULL;
							struct statement* statement = NULL;
							
							error = 0
								?: new_initializer_expression(&e,
									/* location:    */ init->initializer->loc,
									/* initializer: */ init->initializer,
									/* offset:      */ variable->offset,
									/* type:        */ type)
								?: new_expression_statement(&statement, e->loc, e)
								?: statement_ll_append(statements, statement);
							
							tfree(statement);
							tfree(e);
						}
					}
					else if (true
						&& specifiers->storage_class != sc_extern
						&& type->kind != tk_function)
					{
						asm_writer_write_global(
							/* writer: */ writer,
							/* name: */ identifier,
							/* is_static: */ specifiers->storage_class == sc_static,
							/* value: */ init->initializer,
							/* type: */ type);
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
	{
		dpv(statements);
		dpv(statements->head);
		*retval = tinc(statements);
	}
	
	tfree(specifiers);
	tfree(init_list);
	
	tfree(base_type);
	tfree(statements);
	
	
	EXIT;
	return error;
}













