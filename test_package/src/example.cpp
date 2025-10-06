#include "path_planning_lib.h"
#include <vector>
#include <string>

int main() {
    path_planning_lib();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    path_planning_lib_print_vector(vec);
}
