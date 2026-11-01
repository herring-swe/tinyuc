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

# SIMD-accelerated UTF-8 validation and counting. Selects which ISA tiers to
# compile; a runtime check still guards every call. OFF keeps the portable
# implementation only. AUTO compiles every tier supported by the architecture
# and dispatches at runtime (the default).
set(TINYUC_SIMD "AUTO" CACHE STRING "SIMD-accelerated UTF-8 paths (OFF, SSSE3, AVX2, AUTO)")
set_property(CACHE TINYUC_SIMD PROPERTY STRINGS OFF SSSE3 AVX2 AUTO)
if(NOT TINYUC_SIMD MATCHES "^(OFF|SSSE3|AVX2|AUTO)$")
    message(FATAL_ERROR "TINYUC_SIMD must be one of OFF, SSSE3, AVX2, AUTO (got '${TINYUC_SIMD}')")
endif()

# The SIMD kernels are x86-only for now (SSSE3/AVX2).
set(TINYUC_SIMD_X86 FALSE)
if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64|amd64|i[3-6]86|x86)$")
    set(TINYUC_SIMD_X86 TRUE)
endif()

set(TINYUC_SIMD_SSSE3_ENABLED FALSE)
set(TINYUC_SIMD_AVX2_ENABLED FALSE)
if(TINYUC_SIMD STREQUAL "AUTO")
    if(TINYUC_SIMD_X86)
        set(TINYUC_SIMD_SSSE3_ENABLED TRUE)
        set(TINYUC_SIMD_AVX2_ENABLED TRUE)
    endif()
elseif(TINYUC_SIMD STREQUAL "SSSE3")
    if(NOT TINYUC_SIMD_X86)
        message(FATAL_ERROR "TINYUC_SIMD=SSSE3 is only supported on x86")
    endif()
    set(TINYUC_SIMD_SSSE3_ENABLED TRUE)
elseif(TINYUC_SIMD STREQUAL "AVX2")
    if(NOT TINYUC_SIMD_X86)
        message(FATAL_ERROR "TINYUC_SIMD=AVX2 is only supported on x86")
    endif()
    set(TINYUC_SIMD_AVX2_ENABLED TRUE)
endif()

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
    src/private/simd.h
    src/private/utf8_iter.h
    src/private/utf8_lookup_tables.h

    PRIVATE
    src/helpers.c
    src/enum.c
    src/unicode.c

    PRIVATE FILE_SET generated_data TYPE HEADERS BASE_DIRS "${UNICODE_DATA_DIR}" FILES
    ${UNICODE_HEADERS}
)

if(TINYUC_SIMD_SSSE3_ENABLED OR TINYUC_SIMD_AVX2_ENABLED)
    target_sources(tinyuc PRIVATE src/simd_support.c)
endif()

if(TINYUC_SIMD_SSSE3_ENABLED)
    if(NOT MSVC)
        set_source_files_properties(src/simd_ssse3.c PROPERTIES COMPILE_OPTIONS "-mssse3")
    endif()
    target_sources(tinyuc PRIVATE src/simd_ssse3.c)
    target_compile_definitions(tinyuc PRIVATE TINYUC_SIMD_SSSE3)
endif()

if(TINYUC_SIMD_AVX2_ENABLED)
    if(MSVC)
        set_source_files_properties(src/simd_avx2.c PROPERTIES COMPILE_OPTIONS "/arch:AVX2")
    else()
        set_source_files_properties(src/simd_avx2.c PROPERTIES COMPILE_OPTIONS "-mavx2")
    endif()
    target_sources(tinyuc PRIVATE src/simd_avx2.c)
    target_compile_definitions(tinyuc PRIVATE TINYUC_SIMD_AVX2)
endif()

if(TINYUC_SIMD_SSSE3_ENABLED OR TINYUC_SIMD_AVX2_ENABLED)
    message(STATUS "TinyUC SIMD tiers: SSSE3=${TINYUC_SIMD_SSSE3_ENABLED} AVX2=${TINYUC_SIMD_AVX2_ENABLED}")
else()
    message(STATUS "TinyUC SIMD tiers: none (portable C)")
endif()

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
