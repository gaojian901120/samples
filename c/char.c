#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main(int argc,char *argv[]) {
    char *c;
    int d = 97;
    c = (char *) malloc(sizeof(char)+1);
    if(c != NULL) {
        *c = d;
        c++;
    }
    *c = '\0';
    c--;
    printf("%s",c);
}
