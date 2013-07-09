#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
node_ptr f2t(FILE *fp) {
	char *s, **data;
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
char **split(char *str,char *split_str) {
	char *ptr = NULL;
	ptr = strtok(str,split_str);
	while(ptr ! = NULL) {
		printf("%s\n", ptr);
		strcpy(*ret,ptr);
		ptr = strtok(NULL,split_str);
		ret++;
	}
	return ret;
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
