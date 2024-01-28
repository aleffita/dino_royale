cmake_minimum_required(VERSION 3.27)
project(dino_royale)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)

FetchContent_Declare(
        LDtkLoader
        GIT_REPOSITORY "git@github.com:Madour/LDtkLoader.git"
        GIT_TAG "1.5.0"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(LDtkLoader)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY "git@github.com:SFML/SFML.git"
        GIT_TAG "2.6.1"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SRC src/*.cpp src/*.h src/*.hpp engine/*.cpp engine/*.h engine/*.hpp )

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE LDtkLoader sfml-graphics sfml-window sfml-system sfml-audio)