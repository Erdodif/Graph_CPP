cmake_minimum_required(VERSION 3.27)
project(hello)

add_executable(hello main.cpp)
find_package(SDL2 REQUIRED)
find_package(imgui REQUIRED)
find_package(imgui[impl_sdl2] REQUIRED)
find_package(GLEW REQUIRED)
target_link_libraries(hello PUBLIC -lSDL2 -limgui)