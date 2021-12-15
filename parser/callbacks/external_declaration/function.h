
struct translation_unit_ll;
struct function_definition;
struct asm_writer;

int external_declaration_function_callback(
	struct function_definition* function,
	struct asm_writer* asm_writer);
