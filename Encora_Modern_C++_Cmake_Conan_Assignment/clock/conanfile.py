from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps

class ClockLibRecipe(ConanFile):
    name = "clock_lib"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = "graph_lib/1.0"  # Dependency on graph library
    exports_sources = "include/*", "src/*", "CMakeLists.txt"
    generators = "CMakeToolchain", "CMakeDeps"
    
#    def layout(self):
#        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["clock_lib"]

