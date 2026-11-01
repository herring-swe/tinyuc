# This file is part of the TinyUC project
# SPDX-FileCopyrightText: 2026 Åke Svedin <ake@svedin.org>
# SPDX-License-Identifier: MIT

# Target definitions to download and create unicode data

# Define the files needed and their hashes.
# We use fixed version, to be able to verify the hashes and reproduce builds.
# The parser inputs are only downloaded when generating or verifying headers.
set(PARSER_DATA_URLS "")
set(PARSER_DATA_HASHES "")

list(APPEND PARSER_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/UnicodeData.txt)
list(APPEND PARSER_DATA_HASHES "2e1efc1dcb59c575eedf5ccae60f95229f706ee6d031835247d843c11d96470c")

list(APPEND PARSER_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/CaseFolding.txt)
list(APPEND PARSER_DATA_HASHES "ff8d8fefbf123574205085d6714c36149eb946d717a0c585c27f0f4ef58c4183")

list(APPEND PARSER_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/CompositionExclusions.txt)
list(APPEND PARSER_DATA_HASHES "2f239196ef3b5b61db5cc476e9bd80f534d15aa1b74e1be1dea5d042a344c85f")

list(APPEND PARSER_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/SpecialCasing.txt)
list(APPEND PARSER_DATA_HASHES "efc25faf19de21b92c1194c111c932e03d2a5eaf18194e33f1156e96de4c9588")

list(APPEND PARSER_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/auxiliary/GraphemeBreakProperty.txt)
list(APPEND PARSER_DATA_HASHES "d6b51d1d2ae5c33b451b7ed994b48f1f4dc62b2272a5831e7fd418514a6bae89")

list(APPEND PARSER_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/emoji/emoji-data.txt)
list(APPEND PARSER_DATA_HASHES "2cb2bb9455cda83e8481541ecf5b6dfda66a3bb89efa3fa7c5297eccf607b72b")

list(APPEND PARSER_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/DerivedCoreProperties.txt)
list(APPEND PARSER_DATA_HASHES "24c7fed1195c482faaefd5c1e7eb821c5ee1fb6de07ecdbaa64b56a99da22c08")

# Test corpora, only downloaded for the test targets.
set(TEST_DATA_URLS "")
set(TEST_DATA_HASHES "")

list(APPEND TEST_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/NormalizationTest.txt)
list(APPEND TEST_DATA_HASHES "5019ffd530751a741900c849c0e010332f142a3612234639bd200b82138a87db")

list(APPEND TEST_DATA_URLS https://www.unicode.org/Public/17.0.0/ucd/auxiliary/GraphemeBreakTest.txt)
list(APPEND TEST_DATA_HASHES "e2d134d2c52919bace503ebb6a551c1855fe1a1faec18478c78fff254a1793ec")


# Output folder for extracted UCD data. The generated headers live in the
# source tree, so extracted data and temporary verification output stay in the
# build directory.
if(NOT UNICODE_DATA_DIR)
    set(UNICODE_DATA_DIR "${CMAKE_BINARY_DIR}/tinyuc_data")
endif()

# The UCD files are shipped as a compressed archive so the default build needs
# neither Python nor network access. Downloads remain as a fallback for when a
# local file is missing or does not match the expected hash.
set(UNICODE_DATA_ARCHIVE "${CMAKE_SOURCE_DIR}/data/ucd/17.0.0.zip")
set(UNICODE_DATA_FETCHER "${CMAKE_SOURCE_DIR}/cmake/scripts/get_unicode_data.cmake")
set(UNICODE_DATA_DOWNLOADER "${CMAKE_SOURCE_DIR}/cmake/scripts/cmd_download_file.cmake")

set(UNICODE_HEADER_DIR "${CMAKE_SOURCE_DIR}/src/private/unicode")
set(UNICODE_HEADER_NAMES
    unicode_combine.h
    unicode_defines.h
    unicode_props.h
    unicode_mapping.h
    unicode_decomp.h
)
set(UNICODE_HEADERS "")
foreach(NAME ${UNICODE_HEADER_NAMES})
    list(APPEND UNICODE_HEADERS "${UNICODE_HEADER_DIR}/${NAME}")
endforeach()

# Make sure data directory exists
file(MAKE_DIRECTORY "${UNICODE_DATA_DIR}")

if(NOT EXISTS "${UNICODE_DATA_DIR}")
    message(FATAL_ERROR "Could not create directory ${UNICODE_DATA_DIR}")
endif()

# Define commands that provide each file. The commands are only added to a
# target when that category of data is needed, so a normal build does not
# extract or download anything.
set(PARSER_DATA_FILES "")
foreach(DATA_URL DATA_HASH IN ZIP_LISTS PARSER_DATA_URLS PARSER_DATA_HASHES)
    cmake_path(GET DATA_URL FILENAME DATA_FILENAME)
    list(APPEND PARSER_DATA_FILES "${UNICODE_DATA_DIR}/${DATA_FILENAME}")
    add_custom_command(
        OUTPUT "${UNICODE_DATA_DIR}/${DATA_FILENAME}"
        COMMAND "${CMAKE_COMMAND}"
        "-DDATA_URL=${DATA_URL}"
        "-DDATA_DEST=${DATA_FILENAME}"
        "-DDATA_HASH=${DATA_HASH}"
        "-DDATA_DIR=${UNICODE_DATA_DIR}"
        "-DDATA_ARCHIVE=${UNICODE_DATA_ARCHIVE}"
        -P "${UNICODE_DATA_FETCHER}"
        DEPENDS "${UNICODE_DATA_ARCHIVE}" "${UNICODE_DATA_FETCHER}" "${UNICODE_DATA_DOWNLOADER}"
        WORKING_DIRECTORY "${UNICODE_DATA_DIR}"
        COMMENT "Extracting unicode data file: ${DATA_FILENAME}"
        VERBATIM
    )
endforeach()

set(TEST_DATA_FILES "")
foreach(DATA_URL DATA_HASH IN ZIP_LISTS TEST_DATA_URLS TEST_DATA_HASHES)
    cmake_path(GET DATA_URL FILENAME DATA_FILENAME)
    list(APPEND TEST_DATA_FILES "${UNICODE_DATA_DIR}/${DATA_FILENAME}")
    add_custom_command(
        OUTPUT "${UNICODE_DATA_DIR}/${DATA_FILENAME}"
        COMMAND "${CMAKE_COMMAND}"
        "-DDATA_URL=${DATA_URL}"
        "-DDATA_DEST=${DATA_FILENAME}"
        "-DDATA_HASH=${DATA_HASH}"
        "-DDATA_DIR=${UNICODE_DATA_DIR}"
        "-DDATA_ARCHIVE=${UNICODE_DATA_ARCHIVE}"
        -P "${UNICODE_DATA_FETCHER}"
        DEPENDS "${UNICODE_DATA_ARCHIVE}" "${UNICODE_DATA_FETCHER}" "${UNICODE_DATA_DOWNLOADER}"
        WORKING_DIRECTORY "${UNICODE_DATA_DIR}"
        COMMENT "Extracting unicode test data file: ${DATA_FILENAME}"
        VERBATIM
    )
endforeach()

set(PARSER_DIR ${CMAKE_SOURCE_DIR}/tools)
set(PARSER_FILES
    ${PARSER_DIR}/ucparser.py
    ${PARSER_DIR}/ucparser/cli.py
    ${PARSER_DIR}/ucparser/types.py
    ${PARSER_DIR}/ucparser/parser.py
    ${PARSER_DIR}/ucparser/util.py
)


set(TEMPLATE_DIR ${CMAKE_SOURCE_DIR}/tools/ucparser/templates)
set(TEMPLATE_FILES
    ${TEMPLATE_DIR}/combine.h.jinja
    ${TEMPLATE_DIR}/decomp.h.jinja
    ${TEMPLATE_DIR}/defines.h.jinja
    ${TEMPLATE_DIR}/mapping.h.jinja
    ${TEMPLATE_DIR}/props.h.jinja
)

if(TINYUC_GENERATE_UNICODE_DATA OR TINYUC_VERIFY_UNICODE_DATA)
    find_package(Python 3.6 COMPONENTS Interpreter)
    if(NOT Python_FOUND)
        message(FATAL_ERROR "Python 3.6 or later required for processing Unicode data")
    endif()
endif()

if(TINYUC_GENERATE_UNICODE_DATA)
    file(MAKE_DIRECTORY "${UNICODE_HEADER_DIR}")

    add_custom_command(
        OUTPUT ${UNICODE_HEADERS}
        DEPENDS "${PARSER_DATA_FILES}" "${TEMPLATE_FILES}" "${PARSER_FILES}"
        COMMAND "${Python_EXECUTABLE}" "${CMAKE_SOURCE_DIR}/tools/ucparser.py"
        --output-dir "${UNICODE_HEADER_DIR}"
        WORKING_DIRECTORY "${UNICODE_DATA_DIR}"
        COMMENT "Generating unicode data headers in ${UNICODE_HEADER_DIR}"
        VERBATIM
    )

    add_custom_target(unicode_data DEPENDS ${UNICODE_HEADERS} ${PARSER_DATA_FILES})
endif()

# Test corpora are only needed by the test and benchmark targets.
add_custom_target(unicode_test_data DEPENDS ${TEST_DATA_FILES})

if(TINYUC_VERIFY_UNICODE_DATA)
    set(UNICODE_VERIFY_DIR "${CMAKE_CURRENT_BINARY_DIR}/unicode_data_verify")
    set(UNICODE_VERIFY_HEADERS "")
    foreach(NAME ${UNICODE_HEADER_NAMES})
        list(APPEND UNICODE_VERIFY_HEADERS "${UNICODE_VERIFY_DIR}/${NAME}")
    endforeach()

    file(MAKE_DIRECTORY "${UNICODE_VERIFY_DIR}")

    add_custom_command(
        OUTPUT ${UNICODE_VERIFY_HEADERS}
        DEPENDS "${PARSER_DATA_FILES}" "${TEMPLATE_FILES}" "${PARSER_FILES}"
        COMMAND "${CMAKE_COMMAND}" -E make_directory "${UNICODE_VERIFY_DIR}"
        COMMAND "${Python_EXECUTABLE}" "${CMAKE_SOURCE_DIR}/tools/ucparser.py"
        --output-dir "${UNICODE_VERIFY_DIR}"
        WORKING_DIRECTORY "${UNICODE_DATA_DIR}"
        COMMENT "Generating unicode data headers for verification"
        VERBATIM
    )

    add_custom_target(verify_unicode_data ALL
        COMMAND "${CMAKE_COMMAND}"
        -DSOURCE_DIR=${UNICODE_HEADER_DIR}
        -DGENERATED_DIR=${UNICODE_VERIFY_DIR}
        -P "${CMAKE_SOURCE_DIR}/cmake/scripts/verify_unicode_data.cmake"
        DEPENDS ${UNICODE_VERIFY_HEADERS}
        COMMENT "Verifying unicode data headers"
        VERBATIM
    )
endif()
