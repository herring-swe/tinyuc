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

# Enable OpenMP in future maybe
find_package(OpenMP)

tinyuc_add_executable(tinyuc_tests LANGUAGE CXX)

tinyuc_target_sources(tinyuc_tests PRIVATE
    FILE_SET private_headers TYPE HEADERS BASE_DIRS . FILES
    ucd_corpus.h
)

tinyuc_target_sources(tinyuc_tests PRIVATE
    main_doctest.cpp
    ucd_corpus.cpp
    
    # Actual tests
    unicode.cpp

    ${NORM_TEST_FILE}
    ${GRAPHEME_TEST_FILE}
)

target_compile_definitions(tinyuc_tests PRIVATE NORM_TEST_FILE="${NORM_TEST_FILE}")
target_compile_definitions(tinyuc_tests PRIVATE GRAPHEME_TEST_FILE="${GRAPHEME_TEST_FILE}")
target_compile_definitions(tinyuc_tests PRIVATE TINYUC_TEST_EXPECTED_VERSION="${PROJECT_VERSION}")

target_link_libraries(tinyuc_tests PRIVATE tinyuc)

target_include_directories(tinyuc_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

if(OpenMP_FOUND)
    target_link_libraries(tinyuc_tests PRIVATE OpenMP::OpenMP_CXX)
    target_compile_definitions(tinyuc_tests PRIVATE USE_OPENMP)

    # target_link_libraries(tinyuc_tests PRIVATE $<$<CONFIG:Release>:OpenMP::OpenMP_CXX>)
    # target_compile_definitions(tinyuc_tests PRIVATE $<$<CONFIG:Release>:USE_OPENMP>)
endif()

set(doctest_VERSION 2.4.12)

# find_package(doctest ${doctest_VERSION} QUIET)
if(NOT doctest_FOUND)
    message(STATUS "Using internal doctest version ${doctest_VERSION}")
    target_include_directories(tinyuc_tests PRIVATE doctest)
    include(CTest)
    include(doctest/cmake/doctest.cmake)
else()
    message(STATUS "Using external doctest version ${doctest_VERSION}")
    target_link_libraries(tinyuc_tests PRIVATE doctest::doctest)
    include(CTest)

    # How to include doctest.cmake here?
    include(doctest)
endif()

if(NOT CMAKE_CROSSCOMPILING)
    doctest_discover_tests(tinyuc_tests)
endif()

# ----------------------------------------------------------------------------
# Separate internal bench library and sample runner
# ----------------------------------------------------------------------------

add_library(tinyuc_bench STATIC bench/microbench.cpp bench/microbench.h)
tinyuc_target_init(tinyuc_bench LANGUAGE CXX)
target_include_directories(tinyuc_bench PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/bench)

tinyuc_add_executable(tinyuc_benchmarks LANGUAGE CXX)
target_sources(tinyuc_benchmarks PRIVATE
    bench/bench_main.cpp
    bench/unicode_bench.cpp
    ucd_corpus.cpp
)
target_link_libraries(tinyuc_benchmarks PRIVATE tinyuc_bench tinyuc)
target_include_directories(tinyuc_benchmarks PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/bench
    ${CMAKE_SOURCE_DIR}/src
)
target_compile_definitions(tinyuc_benchmarks PRIVATE NORM_TEST_FILE="${NORM_TEST_FILE}")

# ----------------------------------------------------------------------------
# Optional comparisons against external Unicode libraries
#
# Opt-in via TINYUC_BENCH_COMPARE. utf8proc falls back to the vendored copy in
# ext/ when no system package is found. ICU is assumed present on Windows (the
# in-box ICU) and otherwise located with FindICU; where it is missing the
# comparison is skipped with a status message, never a hard failure.
# ----------------------------------------------------------------------------

if(TINYUC_BENCH_COMPARE)
    find_package(utf8proc QUIET)
    if(utf8proc_FOUND)
        set(TINYUC_BENCH_UTF8PROC_TARGET utf8proc::utf8proc)
        set(TINYUC_BENCH_UTF8PROC_FOUND TRUE)
    elseif(EXISTS "${CMAKE_SOURCE_DIR}/ext/utf8proc/utf8proc.c")
        add_library(tinyuc_utf8proc "${CMAKE_SOURCE_DIR}/ext/utf8proc/utf8proc.c")
        target_include_directories(tinyuc_utf8proc SYSTEM PUBLIC "${CMAKE_SOURCE_DIR}/ext/utf8proc")
        if(BUILD_SHARED_LIBS)
            target_compile_definitions(tinyuc_utf8proc PRIVATE UTF8PROC_EXPORTS)
        else()
            target_compile_definitions(tinyuc_utf8proc PUBLIC UTF8PROC_STATIC)
        endif()
        set_target_properties(tinyuc_utf8proc PROPERTIES C_CLANG_TIDY "" OUTPUT_NAME utf8proc)
        if(MSVC)
            target_compile_options(tinyuc_utf8proc PRIVATE /utf-8)
        endif()
        set(TINYUC_BENCH_UTF8PROC_TARGET tinyuc_utf8proc)
        set(TINYUC_BENCH_UTF8PROC_FOUND TRUE)
    else()
        set(TINYUC_BENCH_UTF8PROC_FOUND FALSE)
    endif()

    if(TINYUC_BENCH_UTF8PROC_FOUND)
        message(STATUS "Benchmarks: utf8proc comparison enabled")
        target_compile_definitions(tinyuc_benchmarks PRIVATE TINYUC_BENCH_UTF8PROC)
        target_link_libraries(tinyuc_benchmarks PRIVATE ${TINYUC_BENCH_UTF8PROC_TARGET})
    else()
        message(STATUS "Benchmarks: utf8proc not found, comparison disabled")
    endif()

    # ICU. On Windows the in-box ICU (Windows 10 1703+) is assumed present and
    # used through its C API, which is all it ships. Everywhere else FindICU
    # locates a standard installation, or the comparison is skipped.
    if(WIN32)
        message(STATUS "Benchmarks: ICU comparison enabled (Windows in-box ICU)")
        target_compile_definitions(tinyuc_benchmarks PRIVATE TINYUC_BENCH_ICU)
        target_link_libraries(tinyuc_benchmarks PRIVATE icuuc)
    else()
        find_package(ICU QUIET COMPONENTS uc)
        if(ICU_FOUND)
            message(STATUS "Benchmarks: ICU comparison enabled (ICU ${ICU_VERSION})")
            target_compile_definitions(tinyuc_benchmarks PRIVATE TINYUC_BENCH_ICU)
            target_link_libraries(tinyuc_benchmarks PRIVATE ICU::uc)
        else()
            message(STATUS "Benchmarks: ICU not found, comparison disabled")
        endif()
    endif()
endif()

# Intentionally not registered with CTest: benchmarks are run manually, not as
# part of the default test suite.
