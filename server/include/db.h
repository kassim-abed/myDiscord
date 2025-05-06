// db.h
#ifndef DB_H
#define DB_H

#include <libpq-fe.h>

// Fonction pour établir la connexion à la base de données
void connect_db();

// Fonction pour fermer la connexion à la base de données
void close_db();

// Fonction pour ajouter un utilisateur
void add_user(const char *username, const char *email, const char *password_hash);

// Fonction pour récupérer les messages d'un canal
void get_messages(int channel_id);

// Fonction pour ajouter une réaction à un message
void add_reaction(int message_id, int user_id, const char *emoji);

// Fonction pour récupérer les notifications d'un utilisateur
void get_notifications(int user_id);

#endif // DB_H