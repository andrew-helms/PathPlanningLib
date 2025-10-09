from conan import ConanFile
from conan.tools.layout import basic_layout
from conan.tools.files import copy

class planner_templateRecipe(ConanFile):
    name = "planner_template"
    version = "0.0.1"
    package_type = "header-library"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "include/*"

    # Automatically manage the package ID clearing of settings and options
    implements = ["auto_header_only"]

    def layout(self):
        basic_layout(self)
    

    def package(self):
        copy(self, "include/*", self.source_folder, self.package_folder)

    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []

