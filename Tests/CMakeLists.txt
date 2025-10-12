project(tests)

add_executable(${PROJECT_NAME} src/DijkstrasTest.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} INTERFACE dijkstras)
target_include_directories(${PROJECT_NAME} INTERFACE 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/include")