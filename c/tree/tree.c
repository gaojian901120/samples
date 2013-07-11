#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "tree.h"
void f2t(FILE *fp,tree_node *tree) {
	char *s;
	queue_t data;
	long flen;
    fseek(fp,0L,SEEK_END);
    flen = ftell(fp);
	if((s = (char *) malloc(flen+1)) == NULL) {
		fclose(fp);
		fprintf(stderr,"not enough memory");
		exit(1);
	}
	fseek(fp,0L,SEEK_SET);
	fread(s,flen,1,fp);
	fclose(fp);
	s[flen] = '\0';
	data = split(s," ");
}
queue_t split(char *str,char *split_str) {
	char *ptr = NULL;
	queue_t queue;
	init_queue(&queue);
	ptr = strtok(str,split_str);
	while(ptr != NULL) {
		push_queue(&queue,ptr);
		ptr = strtok(NULL,split_str);
	}
	printf("%s",pop_queue(&queue));
	return queue;
}

void main() {
	FILE *fp;
	tree_node *tree;
	if((fp = fopen("tree.data","r")) ==NULL) {
		fprintf(stderr,"can't open file tree");
		exit(1);
	}
	f2t(fp,tree);
}
