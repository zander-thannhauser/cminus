
#ifdef X64_TARGET
#ifndef ENUM_FREGISTER_ID
#define ENUM_FREGISTER_ID

enum float_register_id
{
	first_fparameter,
	second_fparameter,
	third_fparameter,
	fourth_fparameter,
	fifth_fparameter,
	sixth_fparameter,
	seventh_fparameter,
	eighth_fparameter,
	
	working_f1,
	working_f2,
	working_f3,
	working_f4,
	working_f5,
	working_f6,
	working_f7,
	working_f8,
	
	number_of_float_registers,
};

#define fretval (first_fparameter)

#define number_of_float_parameters (8)

#endif
#endif
