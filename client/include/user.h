#ifndef USER_H
#define USER_H

#include "channel.h"
#include "roles.h"

typedef struct {
    char* username;      // Pseudonyme de l'utilisateur
    Role role;           // Rôle (MEMBER, MODERATOR, etc.)
    Channel** channels;  // Liste des canaux accessibles
    int channel_count;   // Nombre de canaux dans la liste
} User;

// Création et suppression
User* create_user(const char* username, Role role);
void delete_user(User* user);

// Gestion des canaux
void add_user_to_channel(User* user, Channel* channel);
void remove_user_from_channel(User* user, const char* channel_name);

// Vérification des permissions
int can_create_channel(const User* user);
int can_delete_channel(const User* user);
int can_ban_user(const User* user);

// Gestion des bannissements
void ban_user(User* moderator, User* target, const char* channel_name);
int is_banned(const User* user, const char* channel_name);  // À implémenter si besoin

#endif