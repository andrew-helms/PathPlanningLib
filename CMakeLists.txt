cmake_minimum_required(VERSION 3.15)
project(path_planning_lib CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(PlannerTemplate)
add_subdirectory(Implementations)
add_subdirectory(Tests)

#install(TARGETS path_planning_lib)
