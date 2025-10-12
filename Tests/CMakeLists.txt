project(tests)

add_executable(${PROJECT_NAME} src/DijkstrasTest.cpp)

target_link_libraries(${PROJECT_NAME} dijkstras)
target_include_directories(${PROJECT_NAME} PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/include")