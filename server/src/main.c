// main.c
#include <stdio.h>
#include "db.h"

int main() {
    // Connexion à la base de données
    connect_db(); 

    // Ajouter un utilisateur
    add_user("john_doe", "john@example.com", "hashed_password123");

    // Récupérer les messages d'un canal spécifique
    get_messages(1);

    // Ajouter une réaction à un message
    add_reaction(1, 1, ":thumbsup:");

    // Récupérer les notifications d'un utilisateur
    get_notifications(1);

    // Fermeture de la connexion à la base de données
    close_db();
    return 0;
}

