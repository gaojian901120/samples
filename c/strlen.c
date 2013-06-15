#include "stdio.h"
#include "string.h"

main()
{

    char string[] = "october";

    strcpy(string, "september");

    printf("the size of %s is %d and the length is %d\n\n", string, sizeof(string), strlen(string));

    return 0;
}
