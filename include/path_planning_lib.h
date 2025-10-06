#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define PATH_PLANNING_LIB_EXPORT __declspec(dllexport)
#else
  #define PATH_PLANNING_LIB_EXPORT
#endif

PATH_PLANNING_LIB_EXPORT void path_planning_lib();
PATH_PLANNING_LIB_EXPORT void path_planning_lib_print_vector(const std::vector<std::string> &strings);
