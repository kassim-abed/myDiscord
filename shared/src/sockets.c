#include "../include/sockets.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int create_server_socket() {
    int server_fd;
    struct sockaddr_in address;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Erreur de création du socket serveur");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Échec du bind");
        return -1;
    }

    if (listen(server_fd, 3) < 0) {
        perror("Erreur d'écoute");
        return -1;
    }

    return server_fd;
}

int create_client_socket() {
    int client_fd;
    struct sockaddr_in server_address;

    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("Erreur de création du socket client");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (connect(client_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Échec de connexion au serveur");
        return -1;
    }

    return client_fd;
}

void send_message(int socket, const char *msg) {
    send(socket, msg, strlen(msg), 0);
}

void receive_message(int socket, char *buffer, int bufsize) {
    recv(socket, buffer, bufsize, 0);
}
