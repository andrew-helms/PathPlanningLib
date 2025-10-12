cmake_minimum_required(VERSION 3.15)

add_library(planner_template INTERFACE)
target_include_directories(planner_template INTERFACE 
    include
)

# include(CMakePackageConfigHelpers)
# write_basic_package_version_file(
#     "${PROJECT_BINARY_DIR}/planner_templateConfigVersion.cmake"
#     VERSION ${PROJECT_VERSION}
#     COMPATIBILITY AnyNewerVersion
# )

# install(TARGETS planner_template
#         EXPORT planner_templateTargets
#         LIBRARY DESTINATION lib COMPONENT Runtime
#         ARCHIVE DESTINATION lib COMPONENT Development
#         RUNTIME DESTINATION bin COMPONENT Runtime
#         PUBLIC_HEADER DESTINATION include COMPONENT Development
#         BUNDLE DESTINATION bin COMPONENT Runtime
# )

# include(CMakePackageConfigHelpers)
# configure_package_config_file(
#     "${PROJECT_SOURCE_DIR}/cmake/planner_templateConfig.cmake.in"
#     "${PROJECT_BINARY_DIR}/planner_templateConfig.cmake"
#     INSTALL_DESTINATION lib/cmake/planner_template
# )

# install(EXPORT planner_templateTargets DESTINATION lib/cmake/planner_template)
# install(FILES "${PROJECT_BINARY_DIR}/planner_templateConfigVersion.cmake"
#               "${PROJECT_BINARY_DIR}/planner_templateConfig.cmake"
#         DESTINATION lib/cmake/planner_template)
# install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)