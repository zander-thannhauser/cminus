

#include "intregs.h"

const char* intregs[number_of_integer_registers][number_of_register_sizes] =
{
	//              byte,  word,   long,  quad
	[  rax] = { "%al", "%ax", "%eax", "%rax"},
	[ baseptr] = {"%bpl", "%bp", "%ebp", "%rbp"},
	[stackptr] = {"%spl", "%sp", "%esp", "%rsp"},
	
	//                      byte,   word,  long,   quad
	[ rdi] = {"%dil",  "%di", "%edi", "%rdi"},
	[rsi] = {"%sil",  "%si", "%esi", "%rsi"},
	[ third_parameter] = { "%dl",  "%di", "%edx", "%rdx"},
	[rcx] = { "%cl",  "%ci", "%ecx", "%rcx"},
	[ fifth_parameter] = {"%r8b", "%r8w", "%r8d",  "%r8"},
	[ sixth_parameter] = {"%r9b", "%r9w", "%r9d",  "%r9"},
	
	//                byte,    word,    long,    quad
	[ working_1] = {"%r10b", "%r10w", "%r10d", "%r10"},
	[ working_2] = {"%r11b", "%r11w", "%r11d", "%r11"},
	[ working_3] = {"%r12b", "%r12w", "%r12d", "%r12"},
	[ working_4] = {"%r13b", "%r13w", "%r13d", "%r13"},
	[ working_5] = {"%r14b", "%r14w", "%r14d", "%r14"},
	[ working_6] = {"%r15b", "%r15w", "%r15d", "%r15"},
	
	[ divr_reg] = {"%ah", "%dx", "%edx", "%rdx"},
	
};

