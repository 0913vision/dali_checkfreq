
#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/uio.h>
#include<fcntl.h>
#include<sys/syscall.h>
#include<string.h>
#include <netinet/tcp.h>

#define REQUEST_SIZE 100
#define GET_SIZE 4
#define HEADER_SIZE 8
#define SOCK_CLOSED -2
#define SOCK_ERROR -3
#define SUCCESS 2
#define NOT_FOUND "NOTFOUND"
#define PORT 5555

namespace dali {

void print_socket_options (int sockfd);
bool set_recv_window(int sockfd, int len_bytes);
bool set_send_window(int sockfd, int len_bytes);
bool set_tcp_nodelay(int sockfd);
//std::string prefix = "/dev/shm/cache/";

} //namesapce dali
#endif 
