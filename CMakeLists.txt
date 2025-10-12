cmake_minimum_required(VERSION 3.15)
project(path_planning_lib CXX)

add_subdirectory(PlannerTemplate)
add_subdirectory(Implementations)
add_subdirectory(Tests)

#install(TARGETS path_planning_lib)
