add_executable(dijkstras_test src/DijkstrasTest.cpp)

target_include_directories(dijkstras_test PUBLIC include)

target_link_libraries(dijkstras_test INTERFACE dijkstras)
target_include_directories(dijkstras_test INTERFACE 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Implementation/Dijkstras/include")