#ifndef INIT_SOCKET_H
#define INIT_SOCKET_H
#include <netinet/in.h>

#define BACKLOG 20
#define PORT    8080

/**
 * listen_fd : the web server listen file decriptor
 * server_addr: the web server ipv4 address
 * RETURNS: success on 0, error on -1
 */
int init(int *listen_fd,struct sockaddr_in *server_addr)
#endif
