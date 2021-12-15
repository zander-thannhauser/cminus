
#include <sys/types.h>

struct avls
{
	struct avl_tree_t* variables;
	struct avl_tree_t* types;
	struct avl_tree_t* structs;
	struct avl_tree_t* enums;
};

struct scope
{
	struct avls global;
	
	struct layer {
		off_t offset;
		
		struct avls local;
		
		struct layer* prev;
	}* stackhead;
	
	size_t frame_size;
};

