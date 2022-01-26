
#ifdef X64_TARGET
#ifndef ENUM_IREGISTER_ID
#define ENUM_IREGISTER_ID

enum integer_register_id
{
	rax,
	baseptr,
	stackptr,
	
	rdi,
	rsi,
	rdx,
	rcx,
	r8,
	r9,
	
	working_1,
	working_2,
	working_3,
	working_4,
	working_5,
	working_6,
	
	divr_reg,
	
	number_of_integer_registers,
};

#define retval (rax)

#define first_parameter (rdi)
#define second_parameter (rsi)
#define third_parameter (rdx)
#define fourth_parameter (rcx)
#define fifth_parameter (r8)
#define sixth_parameter (r9)

#define divn_reg (retval)
#define divq_reg (retval)

#define number_of_integer_parameters (6)

#endif
#endif
