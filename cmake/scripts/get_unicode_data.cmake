# This file is part of the TinyUC project
# SPDX-FileCopyrightText: 2026 Åke Svedin <ake@svedin.org>
# SPDX-License-Identifier: MIT

# Provide one UCD data file in DATA_DIR.
#
# The file is extracted from the local DATA_ARCHIVE when possible. If the
# archive is missing, does not contain the file, or the extracted file does not
# match DATA_HASH, the file is downloaded from DATA_URL instead.

if(NOT DATA_DIR)
    message(FATAL_ERROR "DATA_DIR not defined")
endif()
if(NOT DATA_URL)
    message(FATAL_ERROR "DATA_URL not defined")
endif()
if(NOT DATA_DEST)
    cmake_path(GET DATA_URL FILENAME DATA_DEST)
    if(NOT DATA_DEST)
        message(FATAL_ERROR "DATA_DEST not defined and could not be derived from DATA_URL")
    endif()
endif()

file(MAKE_DIRECTORY "${DATA_DIR}")
set(DEST_PATH "${DATA_DIR}/${DATA_DEST}")

function(ucd_file_matches)
    if(NOT DATA_HASH)
        if(EXISTS "${DEST_PATH}")
            set(MATCHES TRUE PARENT_SCOPE)
        else()
            set(MATCHES FALSE PARENT_SCOPE)
        endif()
        return()
    endif()

    if(NOT EXISTS "${DEST_PATH}")
        set(MATCHES FALSE PARENT_SCOPE)
        return()
    endif()

    file(SHA256 "${DEST_PATH}" CURRENT_HASH)
    if(CURRENT_HASH STREQUAL DATA_HASH)
        set(MATCHES TRUE PARENT_SCOPE)
    else()
        set(MATCHES FALSE PARENT_SCOPE)
    endif()
endfunction()

ucd_file_matches()
if(MATCHES)
    return()
endif()

if(DATA_ARCHIVE AND EXISTS "${DATA_ARCHIVE}")
    file(ARCHIVE_EXTRACT
        INPUT "${DATA_ARCHIVE}"
        DESTINATION "${DATA_DIR}"
        PATTERNS "${DATA_DEST}"
    )
    ucd_file_matches()
    if(MATCHES)
        return()
    endif()
endif()

execute_process(
    COMMAND "${CMAKE_COMMAND}"
    "-DDATA_URL=${DATA_URL}"
    "-DDATA_DEST=${DATA_DEST}"
    "-DDATA_HASH=${DATA_HASH}"
    -P "${CMAKE_CURRENT_LIST_DIR}/cmd_download_file.cmake"
    WORKING_DIRECTORY "${DATA_DIR}"
    RESULT_VARIABLE DOWNLOAD_RESULT
)

if(NOT DOWNLOAD_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to download ${DATA_URL}")
endif()

ucd_file_matches()
if(NOT MATCHES)
    message(FATAL_ERROR
        "Downloaded ${DATA_DEST} does not match the expected SHA256 hash"
    )
endif()
