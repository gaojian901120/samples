#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *);

void main() {
    char str[] = "Hello";
    char *res;
    strrev(str);
    printf("%s",str);
}
char *strrev(char *str) {
   char *start = str;
   int len = strlen(str);
   char *end = str+len-1;
   char tmp;
   if(str != NULL) { 
     while(start < end) {
       tmp = *start;
       *start++ = *end;
       *end-- = tmp;
     }
   }
}
