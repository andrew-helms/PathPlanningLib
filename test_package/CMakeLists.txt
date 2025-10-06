cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(path_planning_lib CONFIG REQUIRED)

add_executable(example src/example.cpp)
target_link_libraries(example path_planning_lib::path_planning_lib)
