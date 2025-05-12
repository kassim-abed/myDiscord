#include "../include/client.h"
#include "../include/sockets.h"

int main() {
    int client_fd = create_client_socket();
    printf("Connexion au serveur...\n");

    send_message(client_fd, "Hello, serveur !");
    char buffer[256];
    receive_message(client_fd, buffer, sizeof(buffer));
    printf("Réponse du serveur : %s\n", buffer);

    close(client_fd);
    return 0;
}
