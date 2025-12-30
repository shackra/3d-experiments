cmake_minimum_required(VERSION 4.1.2)

project(3DExperiments CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

find_package(OGRE REQUIRED COMPONENTS Bites CONFIG)
set(OGRE_BUILD_DEPENDENCIES OFF) # prefer system-wide OGRE installation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(OGRE_USE_WAYLAND ON) # set this as off if you are under X11

add_subdirectory(cube)
