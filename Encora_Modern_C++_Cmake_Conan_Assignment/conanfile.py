from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps

class ApplicationConan(ConanFile):
    name = "application"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    requires = [
        "clock_lib/1.0",
        "graph_lib/1.0"
    ]

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

