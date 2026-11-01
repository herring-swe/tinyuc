# This file is part of the TinyUC project
# SPDX-FileCopyrightText: 2026 Åke Svedin <ake@svedin.org>
# SPDX-License-Identifier: MIT

# Compare generated Unicode data headers with the copies in the source tree.

if(NOT DEFINED SOURCE_DIR)
    message(FATAL_ERROR "SOURCE_DIR not defined")
endif()
if(NOT DEFINED GENERATED_DIR)
    message(FATAL_ERROR "GENERATED_DIR not defined")
endif()

file(GLOB SOURCE_HEADERS RELATIVE "${SOURCE_DIR}" "${SOURCE_DIR}/unicode_*.h")
file(GLOB GENERATED_HEADERS RELATIVE "${GENERATED_DIR}" "${GENERATED_DIR}/unicode_*.h")
list(SORT SOURCE_HEADERS)
list(SORT GENERATED_HEADERS)

if(NOT SOURCE_HEADERS)
    message(FATAL_ERROR "No Unicode data headers found in ${SOURCE_DIR}")
endif()

if(NOT "${SOURCE_HEADERS}" STREQUAL "${GENERATED_HEADERS}")
    message(FATAL_ERROR
        "Generated Unicode data headers differ from the source tree.\n"
        "  Source:    ${SOURCE_HEADERS}\n"
        "  Generated: ${GENERATED_HEADERS}"
    )
endif()

foreach(HEADER ${SOURCE_HEADERS})
    execute_process(
        COMMAND "${CMAKE_COMMAND}" -E compare_files
        "${SOURCE_DIR}/${HEADER}" "${GENERATED_DIR}/${HEADER}"
        RESULT_VARIABLE COMPARE_RESULT
        OUTPUT_VARIABLE COMPARE_OUTPUT
        ERROR_VARIABLE COMPARE_ERROR
    )
    if(COMPARE_RESULT)
        message(FATAL_ERROR
            "Unicode data header '${HEADER}' does not match the source tree.\n"
            "${COMPARE_OUTPUT}${COMPARE_ERROR}"
            "Regenerate it with -DTINYUC_GENERATE_UNICODE_DATA=ON."
        )
    endif()
endforeach()

message(STATUS "Generated Unicode data headers match the source tree")
