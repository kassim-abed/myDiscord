cmake_minimum_required(VERSION 3.15)
project(mydiscord-c LANGUAGES C)

set(CMAKE_C_STANDARD 99)

# Configuration spécifique pour Windows/MSYS2
if(WIN32)
    # Chemin du compilateur
    set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
    
    # Options pour le support Unicode
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
    
    # Pour le serveur Windows
    add_link_options(-lws2_32)
endif()

# Recherche de GTK4
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# === Configuration du client ===
file(GLOB CLIENT_SOURCES "client/src/*.c")
add_executable(client ${CLIENT_SOURCES})

# Inclusions pour le client
target_include_directories(client PRIVATE 
    client/include
    ${GTK4_INCLUDE_DIRS}
)

# Liens pour le client
target_link_libraries(client PRIVATE 
    ${GTK4_LIBRARIES}
)

# Ajout des flags de compilation GTK
target_compile_options(client PRIVATE ${GTK4_CFLAGS_OTHER})

# === Configuration du serveur ===
# file(GLOB SERVER_SOURCES "server/src/*.c")
# add_executable(server ${SERVER_SOURCES})

# Liens spécifiques pour le serveur Windows
# if(WIN32)
#     target_link_libraries(server PRIVATE ws2_32)
# endif()