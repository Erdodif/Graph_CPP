cmake_minimum_required(VERSION 3.27)
project(cgproj)

file(GLOB CGMAIN_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
set(CGMAIN_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src)

add_executable(cgmain ${CGMAIN_SOURCES})
target_include_directories(cgmain PRIVATE ${CGMAIN_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(cgmain PRIVATE GLEW::GLEW)
target_link_libraries(cgmain PRIVATE glm::glm)
target_link_libraries(cgmain PRIVATE imgui::imgui)

target_link_libraries(
    cgmain
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

target_link_libraries(
    cgmain
    PRIVATE
    $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)

target_link_libraries(cgmain PRIVATE ${GL_LIBRARY})