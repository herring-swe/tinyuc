# This file is part of the TinyUC project
# SPDX-FileCopyrightText: 2026 Åke Svedin <ake@svedin.org>
# SPDX-License-Identifier: MIT

# Build the optional comparison benchmark against external Unicode libraries.
# This file is included from tests/CMakeLists.txt when BUILD_TESTING is on.

set(TINYUC_COMPARE_UTF8PROC_VERSION "2.12.0")
set(TINYUC_COMPARE_ICU_VERSION "79.1")
set(TINYUC_COMPARE_ICU_MIN_VERSION "74.0")
option(TINYUC_COMPARE_DOWNLOAD "Download external libraries for comparison benchmarks" ON)

set(TINYUC_COMPARE_HAS_UTF8PROC FALSE)
set(TINYUC_COMPARE_HAS_ICU FALSE)
set(TINYUC_COMPARE_UTF8PROC_TARGET "")
set(TINYUC_COMPARE_ICU_TARGET "")
set(TINYUC_COMPARE_ICU_I18N_TARGET "")
set(TINYUC_COMPARE_ICU_DATA_LIB "")
set(TINYUC_COMPARE_ICU_RUNTIME_DLLS "")
set(TINYUC_COMPARE_ICU_RUNTIME_DIR "")

function(tinyuc_download_archive name url hash filename out_dir)
    set(_base "${CMAKE_BINARY_DIR}/_deps/${name}")
    set(_archive "${_base}/${filename}")
    set(_source "${_base}/src")

    file(MAKE_DIRECTORY "${_base}")

    if(EXISTS "${_archive}")
        file(SHA256 "${_archive}" _actual_hash)
        if(NOT _actual_hash STREQUAL hash)
            file(REMOVE "${_archive}")
        endif()
    endif()

    if(NOT EXISTS "${_archive}")
        message(STATUS "Downloading ${url}")
        file(DOWNLOAD "${url}" "${_archive}" EXPECTED_HASH SHA256=${hash} STATUS _status)
        list(GET _status 0 _result)
        if(NOT _result EQUAL 0)
            list(GET _status 1 _message)
            message(FATAL_ERROR "Failed to download ${url}: ${_message}")
        endif()
    endif()

    if(NOT EXISTS "${_source}")
        file(ARCHIVE_EXTRACT INPUT "${_archive}" DESTINATION "${_source}")
    endif()

    set(${out_dir} "${_source}" PARENT_SCOPE)
endfunction()

# ----------------------------------------------------------------------------
# utf8proc
# ----------------------------------------------------------------------------

find_package(utf8proc QUIET)
if(utf8proc_FOUND AND TARGET utf8proc::utf8proc)
    message(STATUS "Benchmark comparison: using utf8proc ${utf8proc_VERSION}")
    set(TINYUC_COMPARE_UTF8PROC_TARGET utf8proc::utf8proc)
    set(TINYUC_COMPARE_HAS_UTF8PROC TRUE)
elseif(TINYUC_COMPARE_DOWNLOAD)
    tinyuc_download_archive(
        "utf8proc-${TINYUC_COMPARE_UTF8PROC_VERSION}"
        "https://github.com/JuliaStrings/utf8proc/releases/download/v${TINYUC_COMPARE_UTF8PROC_VERSION}/utf8proc-${TINYUC_COMPARE_UTF8PROC_VERSION}.tar.gz"
        "a393fbef160835fb315bc3e91ba8d86f7a73a7cec9e6198b6c60b848b498bfeb"
        "utf8proc-${TINYUC_COMPARE_UTF8PROC_VERSION}.tar.gz"
        _utf8proc_source
    )
    set(_utf8proc_root "${_utf8proc_source}/utf8proc-${TINYUC_COMPARE_UTF8PROC_VERSION}")

    message(STATUS "Benchmark comparison: building downloaded utf8proc ${TINYUC_COMPARE_UTF8PROC_VERSION}")
    add_library(tinyuc_compare_utf8proc SHARED "${_utf8proc_root}/utf8proc.c")
    target_include_directories(tinyuc_compare_utf8proc PUBLIC "${_utf8proc_root}")
    target_compile_definitions(tinyuc_compare_utf8proc PRIVATE UTF8PROC_EXPORTS)
    set_target_properties(tinyuc_compare_utf8proc PROPERTIES
        OUTPUT_NAME utf8proc
        POSITION_INDEPENDENT_CODE ON
    )

    set(TINYUC_COMPARE_UTF8PROC_TARGET tinyuc_compare_utf8proc)
    set(TINYUC_COMPARE_HAS_UTF8PROC TRUE)
else()
    message(STATUS "Benchmark comparison: utf8proc not found and downloads disabled")
endif()

# ----------------------------------------------------------------------------
# ICU
#
# Find a real ICU installation first. The in-box Windows ICU is deliberately
# not used: it is an older, stripped-down variant and not comparable to a
# regular ICU build. On supported platforms fall back to the official
# prebuilt release, which also gives us a concrete library location for the
# size comparison.
# ----------------------------------------------------------------------------

find_package(ICU ${TINYUC_COMPARE_ICU_MIN_VERSION} QUIET COMPONENTS uc i18n)
if(ICU_FOUND AND TARGET ICU::uc AND TARGET ICU::i18n)
    message(STATUS "Benchmark comparison: using ICU ${ICU_VERSION}")
    set(TINYUC_COMPARE_ICU_TARGET ICU::uc)
    set(TINYUC_COMPARE_ICU_I18N_TARGET ICU::i18n)
    set(TINYUC_COMPARE_HAS_ICU TRUE)

    get_target_property(_icu_uc_location ICU::uc IMPORTED_LOCATION_RELEASE)
    if(NOT _icu_uc_location)
        get_target_property(_icu_uc_location ICU::uc IMPORTED_LOCATION)
    endif()

    if(_icu_uc_location AND NOT _icu_uc_location MATCHES "-NOTFOUND$")
        get_filename_component(_icu_lib_dir "${_icu_uc_location}" DIRECTORY)

        if(WIN32)
            file(GLOB _icu_data "${_icu_lib_dir}/../bin*/icudt*.dll")
        else()
            file(GLOB _icu_data "${_icu_lib_dir}/libicudata.so*")
        endif()

        if(_icu_data)
            list(GET _icu_data 0 TINYUC_COMPARE_ICU_DATA_LIB)
        endif()
    endif()
elseif(TINYUC_COMPARE_DOWNLOAD)
    set(_icu_url "")
    set(_icu_hash "")
    set(_icu_filename "")
    set(_icu_root_prefix "")
    set(_icu_include_sub "include")
    set(_icu_lib_sub "lib")
    set(_icu_bin_sub "bin")
    set(_icu_uc_lib_sub "libicuuc.so.79")
    set(_icu_i18n_lib_sub "libicui18n.so.79")
    set(_icu_data_lib_sub "libicudata.so.79")
    set(_icu_uc_dll_sub "")
    set(_icu_i18n_dll_sub "")

    if(WIN32 AND CMAKE_SYSTEM_PROCESSOR MATCHES "^(AMD64|amd64|x86_64)$")
        set(_icu_url "https://github.com/unicode-org/icu/releases/download/release-${TINYUC_COMPARE_ICU_VERSION}/icu4c-${TINYUC_COMPARE_ICU_VERSION}-Win64-MSVC2026.zip")
        set(_icu_hash "c4ae1cbadb4187007f76f8b1bcf3a10deb699395ab3c74df01362bfdfa0f1ac2")
        set(_icu_filename "icu4c-${TINYUC_COMPARE_ICU_VERSION}-Win64-MSVC2026.zip")
        set(_icu_lib_sub "lib64")
        set(_icu_bin_sub "bin64")
        set(_icu_uc_lib_sub "icuuc.lib")
        set(_icu_i18n_lib_sub "icuin.lib")
        set(_icu_uc_dll_sub "icuuc79.dll")
        set(_icu_i18n_dll_sub "icuin79.dll")
        set(_icu_data_lib_sub "icudt79.dll")
    elseif(UNIX AND NOT APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64|amd64)$")
        set(_icu_url "https://github.com/unicode-org/icu/releases/download/release-${TINYUC_COMPARE_ICU_VERSION}/icu4c-${TINYUC_COMPARE_ICU_VERSION}-Ubuntu24.04-x64.tgz")
        set(_icu_hash "9ceb5bd2f8f876972ac2a48f6471ab10be45cf98d7d5db6d9fce055f4840e47f")
        set(_icu_filename "icu4c-${TINYUC_COMPARE_ICU_VERSION}-Ubuntu24.04-x64.tgz")
        set(_icu_root_prefix "icu/usr/local")
        set(_icu_uc_lib_sub "libicuuc.so.79")
        set(_icu_i18n_lib_sub "libicui18n.so.79")
        set(_icu_data_lib_sub "libicudata.so.79")
    endif()

    if(_icu_url)
        tinyuc_download_archive(
            "icu-${TINYUC_COMPARE_ICU_VERSION}"
            "${_icu_url}"
            "${_icu_hash}"
            "${_icu_filename}"
            _icu_source
        )

        set(_icu_root "${_icu_source}")
        if(_icu_root_prefix)
            set(_icu_root "${_icu_root}/${_icu_root_prefix}")
        endif()

        message(STATUS "Benchmark comparison: using downloaded ICU ${TINYUC_COMPARE_ICU_VERSION} prebuilt")
        if(WIN32)
            add_library(tinyuc_compare_icuuc SHARED IMPORTED)
            set_target_properties(tinyuc_compare_icuuc PROPERTIES
                IMPORTED_IMPLIB "${_icu_root}/${_icu_lib_sub}/${_icu_uc_lib_sub}"
                IMPORTED_LOCATION "${_icu_root}/${_icu_bin_sub}/${_icu_uc_dll_sub}"
                INTERFACE_INCLUDE_DIRECTORIES "${_icu_root}/${_icu_include_sub}"
            )
            add_library(tinyuc_compare_icui18n SHARED IMPORTED)
            set_target_properties(tinyuc_compare_icui18n PROPERTIES
                IMPORTED_IMPLIB "${_icu_root}/${_icu_lib_sub}/${_icu_i18n_lib_sub}"
                IMPORTED_LOCATION "${_icu_root}/${_icu_bin_sub}/${_icu_i18n_dll_sub}"
                INTERFACE_INCLUDE_DIRECTORIES "${_icu_root}/${_icu_include_sub}"
                INTERFACE_LINK_LIBRARIES tinyuc_compare_icuuc
            )
            set(TINYUC_COMPARE_ICU_DATA_LIB "${_icu_root}/${_icu_bin_sub}/${_icu_data_lib_sub}")
            set(TINYUC_COMPARE_ICU_RUNTIME_DLLS
                "${_icu_root}/${_icu_bin_sub}/${_icu_uc_dll_sub}"
                "${_icu_root}/${_icu_bin_sub}/${_icu_i18n_dll_sub}"
                "${_icu_root}/${_icu_bin_sub}/${_icu_data_lib_sub}"
            )
        else()
            add_library(tinyuc_compare_icuuc SHARED IMPORTED)
            set_target_properties(tinyuc_compare_icuuc PROPERTIES
                IMPORTED_LOCATION "${_icu_root}/${_icu_lib_sub}/${_icu_uc_lib_sub}"
                INTERFACE_INCLUDE_DIRECTORIES "${_icu_root}/${_icu_include_sub}"
            )
            add_library(tinyuc_compare_icui18n SHARED IMPORTED)
            set_target_properties(tinyuc_compare_icui18n PROPERTIES
                IMPORTED_LOCATION "${_icu_root}/${_icu_lib_sub}/${_icu_i18n_lib_sub}"
                INTERFACE_INCLUDE_DIRECTORIES "${_icu_root}/${_icu_include_sub}"
                INTERFACE_LINK_LIBRARIES tinyuc_compare_icuuc
            )
            set(TINYUC_COMPARE_ICU_DATA_LIB "${_icu_root}/${_icu_lib_sub}/${_icu_data_lib_sub}")
            set(TINYUC_COMPARE_ICU_RUNTIME_DIR "${_icu_root}/${_icu_lib_sub}")
        endif()

        set(TINYUC_COMPARE_ICU_TARGET tinyuc_compare_icuuc)
        set(TINYUC_COMPARE_ICU_I18N_TARGET tinyuc_compare_icui18n)
        set(TINYUC_COMPARE_HAS_ICU TRUE)
    else()
        message(STATUS "Benchmark comparison: no downloadable ICU package for this platform")
    endif()
else()
    message(STATUS "Benchmark comparison: ICU not found and downloads disabled")
endif()

if(NOT TINYUC_COMPARE_HAS_UTF8PROC AND NOT TINYUC_COMPARE_HAS_ICU)
    message(STATUS "Benchmark comparison: no external libraries available, target skipped")
    return()
endif()

# ----------------------------------------------------------------------------
# Per-language benchmark texts
# ----------------------------------------------------------------------------

set(TINYUC_COMPARE_TEXT_ARCHIVE "${CMAKE_SOURCE_DIR}/data/benchmark.zip")
set(TINYUC_COMPARE_TEXT_DIR "${CMAKE_BINARY_DIR}/tinyuc_benchmark_text")

if(NOT EXISTS "${TINYUC_COMPARE_TEXT_ARCHIVE}")
    message(FATAL_ERROR "Missing benchmark text archive: ${TINYUC_COMPARE_TEXT_ARCHIVE}")
endif()

file(MAKE_DIRECTORY "${TINYUC_COMPARE_TEXT_DIR}")
file(ARCHIVE_EXTRACT
    INPUT "${TINYUC_COMPARE_TEXT_ARCHIVE}"
    DESTINATION "${TINYUC_COMPARE_TEXT_DIR}"
)

# ----------------------------------------------------------------------------
# Comparison target
# ----------------------------------------------------------------------------

if(BUILD_SHARED_LIBS)
    set(_tinyuc_library_type "Shared")
else()
    set(_tinyuc_library_type "Static")
endif()

if(CMAKE_BUILD_TYPE)
    set(_tinyuc_build_config "${CMAKE_BUILD_TYPE}")
else()
    set(_tinyuc_build_config "Multi-Config")
endif()

set(_tinyuc_simd "${TINYUC_SIMD}")
if(TINYUC_SIMD STREQUAL "AUTO")
    if(TINYUC_SIMD_AVX2_ENABLED)
        string(APPEND _tinyuc_simd ", AVX2")
    endif()
    if(TINYUC_SIMD_SSSE3_ENABLED)
        string(APPEND _tinyuc_simd ", SSSE3")
    endif()
endif()

set(TINYUC_COMPARE_BUILD_INFO
    "${_tinyuc_library_type} ${_tinyuc_build_config}, SIMD ${_tinyuc_simd}, ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}, ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_PROCESSOR}"
)

tinyuc_add_executable(tinyuc_compare LANGUAGE CXX)
target_sources(tinyuc_compare PRIVATE
    bench/bench_main.cpp
    bench/bench_reporter.cpp
    bench/compare.cpp
    bench/compare_info.cpp
    ucd_corpus.cpp
)
target_link_libraries(tinyuc_compare PRIVATE tinyuc Catch2::Catch2)
if(TARGET unicode_test_data)
    add_dependencies(tinyuc_compare unicode_test_data)
endif()
target_include_directories(tinyuc_compare PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/include
)
target_compile_definitions(tinyuc_compare PRIVATE
    NORM_TEST_FILE="${NORM_TEST_FILE}"
    GRAPHEME_TEST_FILE="${GRAPHEME_TEST_FILE}"
    "TINYUC_COMPARE_TEXT_DIR=\"${TINYUC_COMPARE_TEXT_DIR}\""
    TINYUC_COMPARE=1
    "TINYUC_COMPARE_BUILD_INFO=\"${TINYUC_COMPARE_BUILD_INFO}\""
    "TINYUC_COMPARE_TINYUC_LIB=\"$<TARGET_FILE:tinyuc>\""
)

if(TINYUC_COMPARE_HAS_ICU)
    # Modern ICU headers use C++17 constructs even in their C API entry points.
    target_compile_features(tinyuc_compare PRIVATE cxx_std_17)
endif()

if(TINYUC_COMPARE_HAS_UTF8PROC)
    target_compile_definitions(tinyuc_compare PRIVATE
        TINYUC_COMPARE_HAS_UTF8PROC
        "TINYUC_COMPARE_UTF8PROC_LIB=\"$<TARGET_FILE:${TINYUC_COMPARE_UTF8PROC_TARGET}>\""
    )
    target_link_libraries(tinyuc_compare PRIVATE ${TINYUC_COMPARE_UTF8PROC_TARGET})
endif()

if(TINYUC_COMPARE_HAS_ICU)
    target_compile_definitions(tinyuc_compare PRIVATE
        TINYUC_COMPARE_HAS_ICU
        "TINYUC_COMPARE_ICU_LIB=\"$<TARGET_FILE:${TINYUC_COMPARE_ICU_TARGET}>\""
        "TINYUC_COMPARE_ICU_I18N_LIB=\"$<TARGET_FILE:${TINYUC_COMPARE_ICU_I18N_TARGET}>\""
    )
    if(TINYUC_COMPARE_ICU_DATA_LIB)
        target_compile_definitions(tinyuc_compare PRIVATE
            "TINYUC_COMPARE_ICU_DATA_LIB=\"${TINYUC_COMPARE_ICU_DATA_LIB}\""
        )
    endif()
    target_link_libraries(tinyuc_compare PRIVATE
        ${TINYUC_COMPARE_ICU_I18N_TARGET}
        ${TINYUC_COMPARE_ICU_TARGET}
    )

    if(TINYUC_COMPARE_ICU_RUNTIME_DIR)
        set_target_properties(tinyuc_compare PROPERTIES
            BUILD_RPATH "${TINYUC_COMPARE_ICU_RUNTIME_DIR}"
        )
    endif()

    foreach(_icu_dll ${TINYUC_COMPARE_ICU_RUNTIME_DLLS})
        add_custom_command(TARGET tinyuc_compare POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different
            "${_icu_dll}" "$<TARGET_FILE_DIR:tinyuc_compare>"
        )
    endforeach()
endif()
