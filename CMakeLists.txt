# This file is part of the TinyUC project
# SPDX-FileCopyrightText: 2026 Åke Svedin <ake@svedin.org>
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.26)

get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(NOT is_multi_config)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the build type")
endif()

project(tinyyc VERSION 0.4.0 LANGUAGES C)

# clangd, clang-tidy, and other tools. The Visual Studio generator still
# will not write this file; use Ninja or a Makefile generator for that.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Special options, do not rename as they have a meaning in CMake
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(BUILD_TESTING "Build tests" ON)

# Internal options and details
option(TINYUC_CLANG_TIDY "Use clang-tidy" OFF)
option(TINYUC_DEVEL "Enables development logging and assertions for debug builds" ON)
option(TINYUC_BENCH_COMPARE "Benchmark against external Unicode libraries (utf8proc, ICU)" OFF)

# External includes
include(GNUInstallDirs)

include(cmake/functions.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(TINYUC_CLANG_TIDY)
    if(WIN32)
        find_program(CLANG_TIDY_EXE clang-tidy HINTS "$ENV{ProgramFiles}/LLVM/bin" NO_CACHE)
    else()
        find_program(CLANG_TIDY_EXE clang-tidy)
    endif()

    if(CLANG_TIDY_EXE)
        message(STATUS "Using clang-tidy: ${CLANG_TIDY_EXE}")

        # set(CMAKE_C_CLANG_TIDY "${CLANG_TIDY_EXE}" -checks=-*,readability-*)
        set(CMAKE_C_CLANG_TIDY clang-tidy;-p=${CMAKE_BINARY_DIR})
    else()
        message(WARNING "Could not find clang-tidy")
    endif()
endif()

# ---------------------------------- Library --------------------------------- #

# Public version.h
set(TINYUC_BUILD_SHARED ${BUILD_SHARED_LIBS})
configure_file(${CMAKE_SOURCE_DIR}/cmake/headers/version.h.cmake.in ${CMAKE_BINARY_DIR}/include/tinyuc/version.h)
install(
    FILES ${CMAKE_BINARY_DIR}/include/tinyuc/version.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tinyuc
)

set(UNICODE_DATA_DIR "${CMAKE_CURRENT_BINARY_DIR}/tinyuc_data")
include(${CMAKE_SOURCE_DIR}/cmake/unicode_data.cmake)

tinyuc_add_library(tinyuc LANGUAGE C)

if(TARGET unicode_data)
    add_dependencies(tinyuc unicode_data)
endif()

tinyuc_target_sources(tinyuc
    PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
    include/tinyuc/diag.h
    include/tinyuc/enum.h
    include/tinyuc/export.h
    include/tinyuc/tinyuc.h
    include/tinyuc/unicode.h

    PRIVATE FILE_SET internal_headers TYPE HEADERS BASE_DIRS src FILES
    src/private/buffer.h
    src/private/helpers.h

    PRIVATE
    src/helpers.c
    src/enum.c
    src/unicode.c

    PRIVATE FILE_SET generated_data TYPE HEADERS BASE_DIRS "${UNICODE_DATA_DIR}" FILES
    ${UNICODE_HEADERS}
)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

# ---------------------------------- Install --------------------------------- #
install(
    TARGETS tinyuc
    EXPORT tinyucTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# ---------------------------------- Export ---------------------------------- #
install(
    EXPORT tinyucTargets
    FILE tinyucTargets.cmake
    NAMESPACE tinyuc::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tinyuc
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/tinyucConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/tinyucConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tinyuc
)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/tinyucConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/tinyucConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/tinyucConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/tinyuc
)
