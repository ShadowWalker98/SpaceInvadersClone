cmake_minimum_required(VERSION 3.27)
project(SpaceInvadersClone)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)
add_executable(SpaceInvadersClone
        main.cpp)
target_link_libraries(SpaceInvadersClone PRIVATE SFML::Graphics)