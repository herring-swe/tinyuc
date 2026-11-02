# This file is part of the TinyUC project
# SPDX-FileCopyrightText: 2026 Åke Svedin <ake@svedin.org>
# SPDX-License-Identifier: MIT

# ----------------------------------------------------------------------------
# Minimal C program
# ----------------------------------------------------------------------------

# tinyuc_add_executable(tinyuc_main)
# tinyuc_target_sources(tinyuc_main PRIVATE main.c)
# target_link_libraries(tinyuc_main PRIVATE tinyuc)

# ----------------------------------------------------------------------------
# Actual tests
# ----------------------------------------------------------------------------

# Define data dir relative to build dir of target tinyuc
get_target_property(TINYUC_SOURCE_DIR tinyuc BINARY_DIR)
set(UNICODE_DATA_DIR "${TINYUC_SOURCE_DIR}/tinyuc_data")
set(NORM_TEST_FILE "${UNICODE_DATA_DIR}/NormalizationTest.txt")
set(GRAPHEME_TEST_FILE "${UNICODE_DATA_DIR}/GraphemeBreakTest.txt")

# if(NOT EXISTS ${NORM_TEST_FILE})
# message(FATAL_ERROR "Could not find ${NORM_TEST_FILE}")
# endif()
enable_language(CXX)

include(CTest)

# Language corpus used by the large benchmark suites.
set(TINYUC_BENCH_TEXT_ARCHIVE "${CMAKE_SOURCE_DIR}/data/benchmark.zip")
set(TINYUC_BENCH_TEXT_DIR "${CMAKE_BINARY_DIR}/tinyuc_benchmark_text")

if(NOT EXISTS "${TINYUC_BENCH_TEXT_ARCHIVE}")
    message(FATAL_ERROR "Missing benchmark text archive: ${TINYUC_BENCH_TEXT_ARCHIVE}")
endif()

file(MAKE_DIRECTORY "${TINYUC_BENCH_TEXT_DIR}")
file(ARCHIVE_EXTRACT
    INPUT "${TINYUC_BENCH_TEXT_ARCHIVE}"
    DESTINATION "${TINYUC_BENCH_TEXT_DIR}"
)

# Catch2 v3. An installed package is used when found; Catch2_DIR or
# Catch2_ROOT can point CMake at an external installation. Otherwise a pinned
# release archive is downloaded and built.
set(TINYUC_CATCH2_VERSION "3.16.1")

find_package(Catch2 3 QUIET)

if(NOT Catch2_FOUND)
    message(STATUS "Using downloaded Catch2 ${TINYUC_CATCH2_VERSION}")
    include(FetchContent)

    set(CATCH_DEVELOPMENT_BUILD OFF CACHE BOOL "" FORCE)
    set(CATCH_BUILD_TESTING OFF CACHE BOOL "" FORCE)
    set(CATCH_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(CATCH_BUILD_BENCHMARKS OFF CACHE BOOL "" FORCE)
    set(CATCH_INSTALL_DOCS OFF CACHE BOOL "" FORCE)
    set(CATCH_INSTALL_EXTRAS OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(
        Catch2
        URL https://github.com/catchorg/Catch2/archive/refs/tags/v${TINYUC_CATCH2_VERSION}.tar.gz
        URL_HASH SHA256=d16bd1b8b2364918bd472cb216394acb93bde6784890df0d91bccfb3f28d777d
        DOWNLOAD_EXTRACT_TIMESTAMP FALSE
    )
    FetchContent_MakeAvailable(Catch2)
else()
    message(STATUS "Using Catch2 ${Catch2_VERSION} at ${Catch2_DIR}")
endif()

if(DEFINED catch2_SOURCE_DIR)
    set(TINYUC_CATCH2_EXTRAS "${catch2_SOURCE_DIR}/extras")
elseif(Catch2_DIR AND EXISTS "${Catch2_DIR}/Catch.cmake")
    set(TINYUC_CATCH2_EXTRAS "${Catch2_DIR}")
endif()

if(TINYUC_CATCH2_EXTRAS)
    include("${TINYUC_CATCH2_EXTRAS}/Catch.cmake")
endif()

tinyuc_add_executable(tinyuc_tests LANGUAGE CXX)

tinyuc_target_sources(tinyuc_tests PRIVATE
    FILE_SET private_headers TYPE HEADERS BASE_DIRS . FILES
    ucd_corpus.h
)

tinyuc_target_sources(tinyuc_tests PRIVATE
    ucd_corpus.cpp

    # Actual tests
    unicode.cpp

    ${NORM_TEST_FILE}
    ${GRAPHEME_TEST_FILE}
)

target_compile_definitions(tinyuc_tests PRIVATE NORM_TEST_FILE="${NORM_TEST_FILE}")
target_compile_definitions(tinyuc_tests PRIVATE GRAPHEME_TEST_FILE="${GRAPHEME_TEST_FILE}")
target_compile_definitions(tinyuc_tests PRIVATE TINYUC_TEST_EXPECTED_VERSION="${PROJECT_VERSION}")

target_link_libraries(tinyuc_tests PRIVATE tinyuc Catch2::Catch2WithMain)
if(TARGET unicode_test_data)
    add_dependencies(tinyuc_tests unicode_test_data)
endif()

target_include_directories(tinyuc_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

if(NOT CMAKE_CROSSCOMPILING)
    if(COMMAND catch_discover_tests)
        catch_discover_tests(tinyuc_tests)
    else()
        add_test(NAME tinyuc_tests COMMAND tinyuc_tests)
    endif()
endif()

# ----------------------------------------------------------------------------
# Benchmarks, also driven by Catch2
# ----------------------------------------------------------------------------

tinyuc_add_executable(tinyuc_benchmarks LANGUAGE CXX)
target_sources(tinyuc_benchmarks PRIVATE
    bench/bench_main.cpp
    bench/bench_reporter.cpp
    bench/unicode_bench.cpp
    ucd_corpus.cpp
)
target_link_libraries(tinyuc_benchmarks PRIVATE tinyuc Catch2::Catch2)
if(TARGET unicode_test_data)
    add_dependencies(tinyuc_benchmarks unicode_test_data)
endif()
target_include_directories(tinyuc_benchmarks PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
target_compile_definitions(tinyuc_benchmarks PRIVATE NORM_TEST_FILE="${NORM_TEST_FILE}")
target_compile_definitions(tinyuc_benchmarks PRIVATE GRAPHEME_TEST_FILE="${GRAPHEME_TEST_FILE}")
target_compile_definitions(tinyuc_benchmarks PRIVATE
    "TINYUC_BENCH_TEXT_DIR=\"${TINYUC_BENCH_TEXT_DIR}\""
)

# ----------------------------------------------------------------------------
# Optional comparisons against external Unicode libraries
#
# Opt-in via TINYUC_BENCH_COMPARE. The comparison benchmark is a separate
# binary. External libraries are used from find_package when available and are
# otherwise downloaded and built/extracted from pinned releases.
# ----------------------------------------------------------------------------

if(TINYUC_BENCH_COMPARE)
    include(${CMAKE_SOURCE_DIR}/cmake/compare_bench.cmake)
endif()

# Intentionally not registered with CTest: benchmarks are run manually, not as
# part of the default test suite.
