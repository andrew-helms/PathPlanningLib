cmake_minimum_required(VERSION 3.15)
project(path_planning_lib CXX)




add_library(path_planning_lib src/path_planning_lib.cpp)
target_include_directories(path_planning_lib PUBLIC include)



set_target_properties(path_planning_lib PROPERTIES PUBLIC_HEADER "include/path_planning_lib.h")
install(TARGETS path_planning_lib)
