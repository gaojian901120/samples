#include <stdlib.h>  
#include <stdio.h> 
  
int main(void)  
{  
    unsigned long i = 1;
    if(*((char*)&i) == 1) {  
        printf("this is little endian.\n");  
        printf("i   == %p . %#x, \n", ((char*)&i)+0, *(((char*)&i)+0) );//  
        printf("i+1 == %p . %#x, \n" , ((char*)&i)+1, *(((char*)&i)+1));//高一个字节  
        printf("i+2 == %p . %#x, \n" , ((char*)&i)+2, *(((char*)&i)+2));//高二个字节  
        printf("i+3 == %p . %#x, \n" , ((char*)&i)+3, *(((char*)&i)+3));//高三个字节  
          
        printf("i-1 == %p . %#x,\n", *(((char*)&i)-1) , ((char*)&i)-1);//低一个字节  
        printf("i+4 == %p . %#x,\n", *(((char*)&i)+4) , ((char*)&i)+4);//高四个字节  
    } else if(*((char*)&i) == 0) {  
        printf("this is big endian. \n");  
    } else {  
        printf("i do not know. \n");  
    }
    return 0;  
}  