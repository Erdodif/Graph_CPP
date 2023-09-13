# Setup

> For proper package manakement, you need a cmake file

## Minimal cmake

```cmake
cmake_minimum_required(VERSION 3.27)
project(hello)

add_executable(hello hello.cpp)
find_package(SDL2 REQUIRED)
target_link_libraries(hello PUBLIC -lSDL2)
```

## Needed cmake for the lessons

```cmake

```

## Arch package list

In order to have everything for cmake, one shall install these packages:

- `vcpkg`
- `imgui`
- `glew`
- `sdl2`
- `libsdl2`

> Some packages can be installed through `vcpkg` more easilly, so this command should help with root privileges:

```sh
vcpkg install sdl2 "sdl2-image[libjpeg-turbo]" glew glm "imgui[sdl2-binding,opengl3-binding]" --triplet x64-linux
```

## Build package

```sh
cmake -S . -B bin
```

## Run

```sh
cd bin
make
./<main>
```

### TODO

One shall fix the cmake for the impl_sdl2
