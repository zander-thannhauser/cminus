
#if 0
#include <stdlib.h>
#include <inttypes.h>

// refer to the address of a global variable
#define ASMGLO(name) \
	&(struct asm_location) { .kind = al_global, .global = name}

// refer to address of string
#define ASMSTR(strid) \
	&(struct asm_location) { .kind = al_string, .string_id = strid}

// refer to data in register
#define ASMREG(reg) \
	&(struct asm_location) { .kind = al_int_register, ._register = reg}

// refer to data in float register
#define ASMFREG(reg) \
	&(struct asm_location) { .kind = al_float_register, ._fregister = reg}

// refer to data refered to by the address in register
#define ASMDEF(reg) \
	&(struct asm_location) { .kind = al_deref_register, ._register = reg}

// refer to literal data
#define ASMLIT(lit) \
	&(struct asm_location) { .kind = al_literal, .literal = lit}

// refer to data stored at an offset location to the stack.
#define ASMOFFB(off) \
	&(struct asm_location) { .kind = al_offsetb, .offset = off}

// refer to data stored at an offset location to the stack.
#define ASMOFFS(off) \
	&(struct asm_location) { .kind = al_offsets, .offset = off}

#include "../enums/intregs.h"
#include "../enums/floatregs.h"

struct asm_location
{
	enum {
		al_global,
		al_string,
		al_offsetb,
		al_offsets,
		al_literal,
		al_int_register,
		al_float_register,
		al_deref_register,
	} kind;
	
	union
	{
		const char* global;
		size_t string_id;
		ssize_t offset;
		uint64_t literal;
		
		enum integer_register_id _register;
		enum float_register_id _fregister;
	};
};









#endif
