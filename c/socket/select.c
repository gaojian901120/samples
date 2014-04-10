/*
 * =====================================================================================
 *
 *       Filename:  poll.c
 *
 *    Description:  poll.c
 *
 *        Version:  1.0
 *        Created:  01/26/2014 06:08:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dingjing 
 *        Company:  sina
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <asm/ioctls.h>
#include <errno.h>
#include <sys/select.h>
#include <fcntl.h>
#define ZERO (fd_set *)0
#define TIMEOUT 50000

int main(int argc, char** argv)
{
    char *ip;
    int startport,endport;
    in_addr_t startip;
    in_addr_t endip;
    int sockfd;
    int nCurrentIPval; //,flags;
    struct sockaddr_in addr; /* 定义addr为sockaddr_in类型 */
    //int ret;
//    unsigned long mode=1; 
    int flags;
    int error;
    fd_set mask;
    struct timeval timeout;

    timeout.tv_sec=0; 
    timeout.tv_usec=TIMEOUT;

    void msg()
    {
        system("clear");
        printf("Usage:\n");
        printf("scan startip endip startport endport\n");
        printf("scan 192.168.1.1 192.168.1.255 20 50\n");
        printf("scan 192.168.1.1 20 50\n");
    }
    if (argc!=4 && argc!=5)
    {
        msg();
        return 0;
    }
    if( 4 == argc)
    {
        ip=argv[1];
        startport=atoi(argv[2]); /* 转换为长整型 */
        endport=atoi(argv[3]);
        if (startport<1||endport>65535)
        {
            printf("port error 1<port<65535\n");
            return 0;
        }
                                    
        addr.sin_family=AF_INET; /* addr结构体中的sin_family定义地址族 */
        addr.sin_addr.s_addr=inet_addr(ip); /* 填写IP，并转换成in_addr */

        int i;
        for (i =startport; i <=endport ; i++)
        {   
            printf("try to connecting %s:%d...\n", ip, i);

            /*************************************************************/
            /* Create an AF_INET stream socket to receive incoming       */
            /* connections on                                            */
            /*************************************************************/
            sockfd=socket(AF_INET,SOCK_STREAM,0);         
            if( -1 == sockfd )
            {
                printf("Err number: %d\n", errno);
                perror("socket");
                //exit( -1 );
                continue;
            }
            /*************************************************************/
            /* Bind the socket                                           */
            /*************************************************************/
            addr.sin_port=htons(i);
            flags=fcntl(sockfd, F_GETFL, 0);
            fcntl(sockfd, F_SETFL, flags|O_NONBLOCK);
            int nRet = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
                         
            if ( -1 == nRet )
            {         
                if(errno != EINPROGRESS)
                {
                    perror("connect");
                    //return -1;
                    continue;
                }
                
                FD_ZERO(&mask);
                FD_SET(sockfd,&mask);
        
                switch (select(sockfd + 1, NULL, &mask, NULL, &timeout)) 
                {
                    case -1:
                        close(sockfd);
                        printf("select error\n"); 
                        perror( "select" );
                        break;
                    case 0:
                        close(sockfd); 
                        break;
                    default: 
                        error = 0;
                        socklen_t len = sizeof(int);
                        if (( 0 == getsockopt(sockfd,SOL_SOCKET,SO_ERROR,&error,&len) ))
                        {   
                            if( 0 == error )
                            { 
                                printf("%s %d open\n", ip, i);
                                close(sockfd);
                            }
                        }
                        break;
                }
            }
            else if( 0 == nRet )
            {     
                close(sockfd);
                printf("Connected: %s %d open\n", ip, i);
            }
        }
    } 
    else if (5 == argc)
    {
        startip=ntohl(inet_addr(argv[1]));
        endip=ntohl(inet_addr(argv[2]));
        
        if (endip < startip)
        {
            in_addr_t nswap = endip;
            endip = startip;
            startip = nswap;
        }
        
        startport=atoi(argv[3]);
        endport=atoi(argv[4]);
        if (startport<1||endport>65535)
        {
            printf("port error 1<port<65535\n");
            return 0;
        }
                        
        to.sin_family=AF_INET;
        //to.sin_addr.s_addr=inet_addr(startip); 
        //to.sin_addr.s_addr=inet_addr(endip); 
        
        for (nCurrentIPval =startip; nCurrentIPval<=endip; nCurrentIPval++)
        {
            to.sin_addr.s_addr = htonl(nCurrentIPval);
        
            int i;
            for (i =startport; i <=endport ; i++)
            {
                printf("try to connecting %s:%d...\n", nCurrentIPval, i);

                to.sin_port=htons(i); 
                
                sockfd=socket(AF_INET,SOCK_STREAM,0);/* 创建套接字 */          
                if( -1 == sockfd )
                {
                    printf("Err number: %d\n", errno);
                    perror("socket");
                    //exit( -1 );
                    continue;
                }
                
                flags=fcntl(sockfd, F_GETFL, 0);
                fcntl(sockfd, F_SETFL, flags|O_NONBLOCK);
                int nRet = connect(sockfd, (struct sockaddr *)&to, sizeof(to));
                             
                if ( -1 == nRet )
                {         
                    if(errno != EINPROGRESS)
                    {
                        perror("connect");
                        //return -1;
                        continue;
                    }
                    
                    FD_ZERO(&mask);
                    FD_SET(sockfd,&mask);

                    timeout.tv_sec=0; 
                    timeout.tv_usec=50000;
            
                    switch (select(sockfd + 1, NULL, &mask, NULL, &timeout)) 
                    {
                        case -1:
                            close(sockfd);
                            printf("select error\n"); 
                            perror( "select" );
                            break;
                        case 0:
                            close(sockfd); 
                            break;
                        default: 
                            error = 0;
                            socklen_t len = sizeof(int);
                            if (( 0 == getsockopt(sockfd,SOL_SOCKET,SO_ERROR,&error,&len) ))
                            {   
                                if( 0 == error )
                                { 
                                    printf("%s %d open\n", ip, i);
                                    close(sockfd);
                                }
                            }
                            break;
                    }
                }
                else if( 0 == nRet )
                {     
                    close(sockfd);
                    printf("Connected: %s %d open\n", ip, i);
                }
            }           
        }
    }
    
    return 0;
}