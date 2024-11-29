from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps

class GraphLibRecipe(ConanFile):
    name = "graph_lib"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "include/*", "src/*", "CMakeLists.txt"
    generators = "CMakeToolchain", "CMakeDeps"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["graph_lib"]

