#include "roles.h"

const char* role_to_string(Role role) {
    switch (role) {
        case MEMBER: return "membre";
        case MODERATOR: return "modérateur";
        case ADMINISTRATOR: return "administrateur";
        default: return "inconnu";
    }
}