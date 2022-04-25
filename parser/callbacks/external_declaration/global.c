
#include <stdio.h>

#include <assert.h>

/*#include <memory/tinc.h>*/
#include <memory/tfree.h>

/*#include <statement/struct.h>*/
/*#include <statement/expression/struct.h>*/

/*#include <expression/struct.h>*/
/*#include <expression/variable/struct.h>*/
/*#include <expression/binary/struct.h>*/

#include <parser/statement_ll/struct.h>
/*#include <parser/declaration_ll/struct.h>*/

/*#include <parser/translation_unit_ll/new.h>*/
/*#include <parser/translation_unit_ll/append.h>*/

/*#include <parser/translation_unit/new_as_declaration.h>*/

#include "global.h"

int external_declaration_global_callback(
	struct statement_ll* globals)
{
	int error = 0;
	struct statement_link* slink;
/*	struct translation_unit_ll* tull = NULL;*/
	ENTER;
	
	dpv(globals->head);
	
	for (slink = globals->head; !error && slink; slink = slink->next)
	{
		// do nothing if function is defined
		TODO;
		#if 0
		struct translation_unit* cur = NULL;
		struct statement* const s = slink->element;
		assert(s->kind == sk_expression);
		struct expression_statement* const se = (typeof(se)) s;
		struct expression* const e = se->expression;
		assert(e->kind == ek_binary);
		struct binary_expression* const be = (typeof(be)) e;
		assert(be->kind == bek_regular_assign);
		struct expression* const ber = be->right;
		assert(ber->kind == ek_variable);
		struct variable_expression* const ve = (typeof(ve)) ber;
		struct expression* const bel = be->left;
		
		if (bel->kind != ek_literal)
		{
			TODO;
			error = 1;
		}
		else error = 0
			?: new_translation_unit_as_declaration(&cur,
				ve->variable, (struct literal_expression*) bel)
			?: translation_unit_ll_append(tull, cur);
		
		tfree(cur);
		#endif
		TODO;
	}
	
	tfree(globals);
	
	EXIT;
	return error;
}








