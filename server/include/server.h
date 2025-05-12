#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Fonction pour initialiser le serveur
int init_server(int *server_fd, struct sockaddr_in *address);

// Fonction pour accepter une connexion client
int accept_client(int server_fd, struct sockaddr_in *address);

// Fonction pour gérer la communication avec le client
void handle_client(int client_socket);

#endif // SERVER_H
