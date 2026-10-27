# This file is part of the TinyUC project
# SPDX-FileCopyrightText: 2026 Åke Svedin <ake@svedin.org>
# SPDX-License-Identifier: MIT
# TODO: This file needs to be verified

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout
from conan.tools.build import can_run
from conan.tools.scm import Git


class TinyucConan(ConanFile):
    name = "tinyuc"
    version = "0.4.0"
    languages = "C"

    description = "A small C library for unicode handling with focus on UTF-8"
    license = "MIT"
    author = "Åke Svedin - <ake@svedin.org>"
    homepage = "https://github.com/herring-swe/tinyuc"
    url = "https://github.com/herring-swe/tinyuc"
    topics = (
        "c",
        "library",
        "unicode",
        "normalization",
        "case-folding",
        "grapheme",
    )  # optional topic

    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
    }

    exports_sources = (
        "CMakeLists.txt",
        "cmake/*",
        "src/*",
        "include/*",
        "tests/*",
        "LICENSE",
        "README.md",
    )

    # def configure(self):
    #     # We don't need C++, verify if lanuage setting do this for us
    #     self.settings.rm_safe("compiler.libcxx")
    #     self.settings.rm_safe("compiler.cppstd")

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def build_requirements(self):
        self.tool_requires("cmake/[^3.28]")
        self.tool_requires("ninja/[^1.13]")
        self.test_requires("doctest/[^2.4.12]")

    def source(self):
        git = Git(self)
        git.clone(self.url, target=".")
        # git.checkout(f"v{self.version}")

    def layout(self):
        # Should be default
        self.folders.build_folder_vars = [
            "settings.os",
            "settings.compiler",
            "settings.compiler.version",
            "settings.arch",
            "settings.build_type",
        ]
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self, generator="Ninja")
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if can_run(self):
            cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        # FIXME
        pass
