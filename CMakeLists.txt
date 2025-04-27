cmake_minimum_required(VERSION 3.16)

project(TSP_ACO)

# Répertoires
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/inc)

# Où sera placé l'exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

# Fichiers sources
file(GLOB_RECURSE SOURCES
    "${SRC_DIR}/*.cpp"
)

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Dossiers d'include
target_include_directories(${PROJECT_NAME} PRIVATE
    ${INC_DIR}
)

# Lien avec SFML
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)
