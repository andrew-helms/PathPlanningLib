cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(planner_template CONFIG REQUIRED)

add_executable(example src/example.cpp)
target_link_libraries(example planner_template::planner_template)
