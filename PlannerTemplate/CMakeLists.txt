cmake_minimum_required(VERSION 3.15)

project(planner_template LANGUAGE CXX)

add_library(PathPlanner INTERFACE)
target_include_directories(PathPlanner INTERFACE include)