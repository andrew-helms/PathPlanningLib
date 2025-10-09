cmake_minimum_required(VERSION 3.15)
project(dijkstras LANGUAGE CXX)

add_library(dijkstras src/Dijkstras.cpp)
target_include_directories(dijkstras PUBLIC include)

set_target_properties(dijkstras PROPERTIES PUBLIC_HEADER "include/dijkstras.h")
install(TARGETS dijkstras)
