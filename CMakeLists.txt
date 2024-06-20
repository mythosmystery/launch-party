cmake_minimum_required(VERSION 3.0)

# Project name
project(LaunchParty)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the path to the raylib submodule
set(RAYLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/libs/raylib)

# Include ExternalProject module
include(ExternalProject)

# Define an external project for raylib
ExternalProject_Add(
    raylib_project
    PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/bin/raylib
    SOURCE_DIR ${RAYLIB_DIR}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/Vendor/bin/raylib
)

# Specify the paths for the raylib include and library directories
ExternalProject_Get_Property(raylib_project install_dir)
set(RAYLIB_INCLUDE_DIR ${install_dir}/include)
set(RAYLIB_LIBRARY_DIR ${install_dir}/lib)

# Include raylib headers
include_directories(${RAYLIB_INCLUDE_DIR})

# Find all .cpp files in the src directory
file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Create the executable
add_executable(LaunchParty ${SOURCE_FILES})

# Link the raylib library
add_dependencies(LaunchParty raylib_project)
target_link_libraries(LaunchParty ${RAYLIB_LIBRARY_DIR}/libraylib.a)

# Platform-specific configurations
if(WIN32)
    # Additional settings for Windows, if any
elseif(APPLE)
    # Additional settings for macOS, if any
    target_link_libraries(LaunchParty "-framework IOKit")
    target_link_libraries(LaunchParty "-framework Cocoa")
    target_link_libraries(LaunchParty "-framework OpenGL")
elseif(UNIX)
    # Additional settings for Linux, if any
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(PC REQUIRED raylib)
    target_link_libraries(LaunchParty ${PC_LIBRARIES})
endif()

# Print useful messages
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Raylib directory: ${RAYLIB_DIR}")
