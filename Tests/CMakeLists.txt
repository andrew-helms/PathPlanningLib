project(tests)

add_executable(${PROJECT_NAME} src/tests.cpp src/DijkstrasTest.cpp src/AStarTest.cpp src/Action2D.cpp src/State2D.cpp)

target_link_libraries(${PROJECT_NAME} path_planning_lib)
target_include_directories(${PROJECT_NAME} PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/include")