typedef struct _tree_node_struct {
	char *data;
	struct _tree_node_struct *lchild,*rchild;
} tree_node;
typedef tree_node *tree_node_ptr;
void f2t(FILE *fp,tree_node *tree);
queue_t split(char *str,char *split_str);