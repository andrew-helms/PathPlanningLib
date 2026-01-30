cmake_minimum_required(VERSION 3.15)

project(astar)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
    ${PROJECT_SOURCE_DIR}/include
    # $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    # $<INSTALL_INTERFACE:include>`
)

target_link_libraries(${PROJECT_NAME} INTERFACE dijkstras)