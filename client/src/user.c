#include "user.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Crée un utilisateur
User* create_user(const char* username, Role role) {
    User* user = (User*)malloc(sizeof(User));
    if (user) {
        user->username = strdup(username);
        user->role = role;
        user->channels = NULL;
        user->channel_count = 0;
    }
    return user;
}

// Libère la mémoire
void delete_user(User* user) {
    if (user) {
        free(user->username);
        free(user->channels);
        free(user);
    }
}

// Ajoute un canal à la liste de l'utilisateur
void add_user_to_channel(User* user, Channel* channel) {
    if (!user || !channel) return;

    user->channels = (Channel**)realloc(user->channels, (user->channel_count + 1) * sizeof(Channel*));
    user->channels[user->channel_count++] = channel;
}

// Retire un canal de la liste
void remove_user_from_channel(User* user, const char* channel_name) {
    if (!user || !channel_name) return;

    for (int i = 0; i < user->channel_count; i++) {
        if (strcmp(user->channels[i]->name, channel_name) == 0) {
            // Décale les éléments restants
            for (int j = i; j < user->channel_count - 1; j++) {
                user->channels[j] = user->channels[j + 1];
            }
            user->channel_count--;
            user->channels = (Channel**)realloc(user->channels, user->channel_count * sizeof(Channel*));
            break;
        }
    }
}

// Vérifie les permissions
int can_create_channel(const User* user) {
    return user && (user->role == MODERATOR || user->role == ADMINISTRATOR);
}

int can_delete_channel(const User* user) {
    return user && (user->role == ADMINISTRATOR);
}

int can_ban_user(const User* user) {
    return user && (user->role == MODERATOR || user->role == ADMINISTRATOR);
}

// Bannit un utilisateur d'un canal
void ban_user(User* moderator, User* target, const char* channel_name) {
    if (!moderator || !target || !channel_name || !can_ban_user(moderator)) return;
    remove_user_from_channel(target, channel_name);
}

// (Optionnel) Vérifie si un utilisateur est banni
int is_banned(const User* user, const char* channel_name) {
    // Implémentation possible avec une liste noire dans Channel
    return 0;
}