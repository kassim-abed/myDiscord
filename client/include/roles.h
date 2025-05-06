#ifndef ROLES_H
#define ROLES_H

typedef enum {
    MEMBER,
    MODERATOR,
    ADMINISTRATOR
} Role;

const char* role_to_string(Role role);

#endif