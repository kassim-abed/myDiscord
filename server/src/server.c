#include "../include/server.h"
#include "../include/sockets.h"

int main() {
    int server_fd = create_server_socket();
    printf("Serveur en attente de connexions...\n");

    int client_socket = accept(server_fd, NULL, NULL);
    printf("Client connecté !\n");

    char buffer[256];
    receive_message(client_socket, buffer, sizeof(buffer));
    printf("Message reçu du client : %s\n", buffer);

    send_message(client_socket, "Message reçu !");
    close(client_socket);
    close(server_fd);

    return 0;
}
