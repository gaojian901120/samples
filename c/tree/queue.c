#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
void init_queue(queue_t *queue) {
	queue->head = NULL;
	queue->tail = NULL; 
	queue->length = 0;
}

void push_queue(queue_t *queue, elem_t data) {
	queue_node_t *node;
	node = (queue_node_t *) malloc(sizeof(queue_node_t));
	if(node == NULL) {
		printf("内存分配失败!");
		exit(1);
	}
	node->data = (elem_t) malloc(strlen(data));
	if(node->data  == NULL) {
		printf("内存分配失败!");
		exit(1);
	}
	strcpy(node->data,data);
	node->next = NULL;
	if(queue->head == NULL) {
		node->prev = NULL;
		queue->head = node;
		queue->tail = node;
	} else {
		node->prev = queue->tail;
		queue->tail->next = node;
		queue->tail = node;
	}
	queue->length++;
}

elem_t pop_queue(queue_t *queue) {
	if(queue->tail == NULL) {
		return NULL;
	}
	elem_t data = (elem_t) malloc(strlen(queue->tail->data));
	if(data == NULL) {
		printf("内存分配失败!");
		exit(1);
	}
	strcpy(data,queue->tail->data);
	queue_node_t *tail_node;
	tail_node = queue->tail;

	queue->tail->prev->next = NULL;
	queue->tail = queue->tail->prev;
	queue->length--;
	free(tail_node);
	return data;
}
int is_empty(queue_t *queue) {
	if(queue->head = NULL) {
		return 1;
	} else {
		return 0;
	}
}
void clear_queue(queue_t *queue) {
	queue_node_t *node = queue->head;
	while(node) {
		queue->head = queue->head->next;
		free(node);
		node = queue->head;
	}
	queue->tail = NULL;
}