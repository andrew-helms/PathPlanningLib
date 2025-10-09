#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define DIJKSTRAS_EXPORT __declspec(dllexport)
#else
  #define DIJKSTRAS_EXPORT
#endif

DIJKSTRAS_EXPORT void dijkstras();
DIJKSTRAS_EXPORT void dijkstras_print_vector(const std::vector<std::string> &strings);
