# Raylib Boilerplate

## Dependencies
* Raylib
* Raylib-cpp (submodule)
* CMake
* Make
* Task

## Build
`git submodule init && git submodule update`
`task build`
`task run`

## Cross Compile for Windows

Deps:
* mingw-w64
* raylib 5.0 (should be placed in `/opt/raylib-windows`)

Build:
`task build-win`
