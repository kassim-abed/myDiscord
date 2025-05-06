// db.c
#include "../include/db.h"
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

PGconn *conn;

// Connexion à la base de données
void connect_db() {
    const char *conninfo = "dbname=MyDiscord user=postgres password=Azadi23 host=localhost";
    conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        exit(1);
    }
    printf("Connected to database\n");
}

// Fermeture de la connexion à la base de données
void close_db() {
    PQfinish(conn);
    printf("Connection closed\n");
}

// Ajouter un utilisateur à la base de données
void add_user(const char *username, const char *email, const char *password_hash) {
    char query[512];
    snprintf(query, sizeof(query), 
            "INSERT INTO users (username, email, password_hash) VALUES ('%s', '%s', '%s')", 
            username, email, password_hash);

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "INSERT command failed: %s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    PQclear(res);
    printf("User added successfully\n");
}

// Récupérer les messages d'un canal spécifique
void get_messages(int channel_id) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM messages WHERE channel_id = %d", channel_id);

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "SELECT command failed: %s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        char *message = PQgetvalue(res, i, 2);  // Contenu du message
        printf("Message: %s\n", message);
    }

    PQclear(res);
}

// Ajouter une réaction à un message
void add_reaction(int message_id, int user_id, const char *emoji) {
    char query[512];
    snprintf(query, sizeof(query), 
            "INSERT INTO reactions (message_id, user_id, emoji) VALUES (%d, %d, '%s')", 
            message_id, user_id, emoji);

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "INSERT command failed: %s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }
    PQclear(res);
    printf("Reaction added successfully\n");
}

// Récupérer les notifications d'un utilisateur
void get_notifications(int user_id) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT * FROM notifications WHERE user_id = %d", user_id);

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "SELECT command failed: %s", PQerrorMessage(conn));
        PQclear(res);
        return;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        char *notification = PQgetvalue(res, i, 2);  // Message de notification
        printf("Notification: %s\n", notification);
    }

    PQclear(res);
}
