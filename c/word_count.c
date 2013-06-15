#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
#define NWORDS (sizeof words/sizeof words[0])
*/
#define NWORDS 26
typedef struct _word_struct{
    char c;
    int count;
} word;
void cout(char *,word *);
word *init();
void show(word *);
main(int argc, char *argv[]) {
    int i, len, str_len=0;
    char *str, *str_p;
    for(i=1;i<argc;i++) {
        str_len += strlen(argv[i]);
    }
    str = (char *) malloc(sizeof(char)*str_len+1);
    if(str != NULL) {
        str_p = str;
        for(i=1;i<argc;i++) {
            len = strlen(argv[i]);
            memcpy(str_p,argv[i],len);
            str_p += len;
        }
        *str_p = '\0';
    }
    word *words_table = init();
    //show(words_table);
    cout(str, words_table);
    show(words_table);
}
word *init() {
    int c=97;
    int word_count=0;
    word *words_table, *words_table_p;
    words_table = (word *) malloc(NWORDS*sizeof(word));
    if(words_table != NULL) {
        words_table_p = words_table;
        while(word_count<NWORDS) {
           words_table_p->c = (char) c;
           words_table_p->count = 0;
           word_count++;
           c++;
           words_table_p++;
        }
    }
    return words_table;
}
void cout(char* str, word* words_table) {
    int i, word_count;
    word *words_table_p;
    words_table_p = words_table;
    char *str_p;
    str_p = str;
    while(*str_p != '\0') {
        for(word_count=0;word_count<NWORDS;word_count++) {
            if(*str_p == words_table_p->c) {
                words_table_p->count++;
            }
            words_table_p++;
        }
        words_table_p -= NWORDS;
        str_p++;
    }
}
void show(word *words_table) {
    int word_count = 0;
    word *words_table_p;
    words_table_p = words_table;
    while(word_count<NWORDS) {
        printf("%c %d\n",words_table_p->c,words_table_p->count);
        words_table_p++;
        word_count++;
    }
}
