cmake_minimum_required(VERSION 3.20)
project(low_level)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(low_level main.cpp)
cmake_minimum_required(VERSION 3.20)
project(low_level)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Charger CPR
FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.10.4
)
FetchContent_MakeAvailable(cpr)

# Créer l'exécutable
add_executable(low_level  main.cpp)

# Lier CPR à ton programme
target_link_libraries(low_level PRIVATE cpr::cpr)
