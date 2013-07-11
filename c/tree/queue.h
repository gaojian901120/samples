typedef char *elem_t;
typedef struct _queue_node_struct {
	elem_t data;
	struct _queue_node_struct *prev;
	struct _queue_node_struct *next;
} queue_node_t;
typedef struct _queue_struct {
	queue_node_t *head;
	queue_node_t *tail;
	size_t length;
} queue_t;
void init_queue(queue_t *queue);
void push_queue(queue_t *queue, elem_t data);
elem_t pop_queue(queue_t *queue);
int is_empty(queue_t *queue);
void clear_queue(queue_t *queue);