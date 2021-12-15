
#include <stdio.h>
#include <string.h>

#include <debug.h>

#include "../tables/intregs.h"
#include "../tables/floatregs.h"

#include "struct.h"
#include "write.h"

char* write_asm_location(
	struct asm_location* this,
	enum register_size rsize,
	char* buffer)
{
	ENTER;
	
	switch (this->kind)
	{
		case al_global:
			sprintf(buffer, "%s@PLT", this->global);
			break;
		
		case al_string:
			sprintf(buffer, ".string_%lu(%%rip)", this->string_id);
			break;
		
		case al_literal:
			sprintf(buffer, "$%lu", this->literal);
			break;
		
		case al_offset:
			sprintf(buffer, "%li(%s)", -this->offset, "%rbp");
			break;
		
		case al_offsets:
			sprintf(buffer, "%li(%s)", this->offset, "%rsp");
			break;
		
		case al_register:
		{
			const char* regname = intregs[this->_register][rsize];
			
			dpvs(regname);
			assert(regname);
			
			sprintf(buffer, "%s", regname);
			break;
		}
		
		case al_float_register:
		{
			const char* regname = floatregs[this->_fregister];
			
			dpvs(regname);
			assert(regname);
			
			sprintf(buffer, "%s", regname);
			break;
		}
		
		case al_deref_register:
		{
			const char* regname = intregs[this->_register][quadword];
			
			dpvs(regname);
			assert(regname);
			
			sprintf(buffer, "(%s)", regname);
			break;
		}
	}
	
	dpvs(buffer);
	
	EXIT;
	return buffer;
}














