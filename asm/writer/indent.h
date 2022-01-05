

#ifdef VERBOSE_ASSEMBLY
struct asm_writer;
struct expression;

int asm_writer_indent2(struct asm_writer* this, const char* fmt, ...);
#endif
