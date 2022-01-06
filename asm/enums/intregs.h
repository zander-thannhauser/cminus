
#ifndef ENUM_IREGISTER_ID
#define ENUM_IREGISTER_ID

enum integer_register_id
{
	retval,
	baseptr,
	stackptr,
	
	first_parameter,
	second_parameter,
	third_parameter,
	fourth_parameter,
	fifth_parameter,
	sixth_parameter,
	
	working_1,
	working_2,
	working_3,
	working_4,
	working_5,
	working_6,
	
	divr_reg,
	
	number_of_integer_registers,
};

#define divn_reg (retval)
#define divq_reg (retval)

#define number_of_integer_parameters (6)

#endif
