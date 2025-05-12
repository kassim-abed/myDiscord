#ifndef SOCKETS_H
#define SOCKETS_H

#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 8080

int create_server_socket();
int create_client_socket();
void send_message(int socket, const char *msg);
void receive_message(int socket, char *buffer, int bufsize);

#endif
