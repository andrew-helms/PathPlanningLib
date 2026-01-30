from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class path_planning_libRecipe(ConanFile):
    name = "path_planning_lib"
    version = "0.0.1"
    package_type = "library"

    # Optional metadata
    license = "<Put the package license here>"
    author = "Andrew Helms helmsandrew3@gmail.com"
    url = "https://github.com/andrew-helms/PathPlanningLib"
    description = "Library for a generic path planner."
    topics = ("Path Planning", "AStar", "Dijkstras")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # generators = "CMakeDeps"

    # Sources are located in the same place as this recipe, copy them to the recipe
    # This is wrong, needs build and install the outputs of PlannerTemplate and Implementations libraries
    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def requirements(self):
        self.requires("imgui/1.92.5-docking")

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def layout(self):
        cmake_layout(self)
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["path_planning_lib"]

