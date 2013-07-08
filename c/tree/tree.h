typedef struct _node_struct node;
typedef node *node_ptr;
struct _node_struct {
	char *data;
	node *lchild,*rchild;
};
node_ptr f2t(FILE *fp);
char *split(char *str,char *split_str);

