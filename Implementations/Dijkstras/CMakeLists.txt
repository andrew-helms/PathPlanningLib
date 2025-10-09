cmake_minimum_required(VERSION 3.15)
project(dijkstras CXX)




add_library(dijkstras src/dijkstras.cpp)
target_include_directories(dijkstras PUBLIC include)



set_target_properties(dijkstras PROPERTIES PUBLIC_HEADER "include/dijkstras.h")
install(TARGETS dijkstras)
