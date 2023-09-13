cmake_minimum_required(VERSION 3.27)
project(hello)

add_executable(hello hello.cpp)
find_package(SDL2 REQUIRED)
target_link_libraries(hello PUBLIC -lSDL2)