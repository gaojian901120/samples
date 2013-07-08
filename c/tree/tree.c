#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#define BUF 256
node_ptr f2t(FILE *fp) {
	char *s,*s_ptr,tmp[BUF],c;
	s = malloc(sizeof(char)*BUF);
	s_ptr = s;
	while(!feof(fp)) {
		c = fgetc(fp);
		*s_ptr = c;
		s_ptr++;
	}
	s_ptr = "\0";
	printf("%s\n", s);
	fclose(fp);
}
char **split(char *str,char *split_str) {
	char *ptr;

	ptr = strstr(str,split_str);
	if(ptr == NULL) {
		return -1;
	}
	ptr = ptr + strlen(split_str);
	int i=0;
	while(*ptr ! = "\0") {

	}
}
void main() {
	FILE *fp;
	node *tree;
	if((fp = fopen("tree.data","r")) ==NULL) {
		fprintf(stderr,"can't open file tree");
		exit(1);
	}
	tree = f2t(fp);
}
