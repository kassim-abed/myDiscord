cmake_minimum_required(VERSION 3.10)
project(myDiscord C)

set(CMAKE_C_STANDARD 99)

# Forcer un programme console, pas GUI
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mconsole")

# Ajoute les includes pour MinGW PostgreSQL
include_directories("C:/msys64/mingw64/include")

# Ajoute les libs pour MinGW PostgreSQL
link_directories("C:/msys64/mingw64/lib")

# add_executable(client
#     client/src/db.c
#     # Ajoute ici d'autres fichiers si besoin
# )
# target_link_options(client PRIVATE -mconsole)
# Lien avec la bibliothèque pq pour PostgreSQL
# target_link_libraries(client PRIVATE pq)

# Si tu utilises GTK aussi :
find_package(PkgConfig REQUIRED)
# pkg_check_modules(GTK REQUIRED gtk4)
# include_directories(${GTK_INCLUDE_DIRS})
# link_directories(${GTK_LIBRARY_DIRS})
# target_link_libraries(client PRIVATE ${GTK_LIBRARIES})

# Ajoute cette ligne pour forcer une application console
# set_target_properties(client PROPERTIES LINK_FLAGS "-mconsole")

# Ajouter le dossier "include" pour rechercher les fichiers d'en-tête
include_directories(include)

# Ajouter le dossier "src" pour rechercher les fichiers source
set(SOURCE_FILES src/main.c src/db.c)

# /////////////////////////////////////////

# === Server ===
file(GLOB SERVER_SOURCES "server/src/*.c")
add_executable(server ${SERVER_SOURCES})
include_directories(server/include) 
target_link_libraries(server PRIVATE  ws2_32 pq ${PG_PORT_LIBRARY} ${PG_COMMON_LIBRARY} )
set(CMAKE_VERBOSE_MAKEFILE ON)