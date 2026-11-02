/**
 * @file compare_info.cpp
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Version and build information for the comparison benchmark.
 */

#include "compare_info.h"

#include <tinyuc/version.h>

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
#include <utf8proc.h>
#endif

#ifdef TINYUC_COMPARE_HAS_ICU
#include <unicode/uchar.h>
#include <unicode/uversion.h>
#endif

#include <cstdint>
#include <fstream>
#include <iomanip>
#include <ios>
#include <sstream>
#include <string>
#include <vector>

namespace {

std::string format_size(std::uintmax_t bytes)
{
    if (bytes == 0)
        return "unknown size";

    static const char* const units[] = {"B", "KB", "MB", "GB"};
    double value = static_cast<double>(bytes);
    std::size_t unit = 0;
    while (value >= 1024.0 && unit + 1 < sizeof(units) / sizeof(units[0]))
    {
        value /= 1024.0;
        ++unit;
    }

    std::ostringstream output;
    output << std::fixed << std::setprecision(unit == 0 ? 0 : 1) << value << ' ' << units[unit];
    return output.str();
}

std::uintmax_t file_size(const char* path)
{
    if (path == nullptr || *path == '\0')
        return 0;

    std::ifstream stream(path, std::ios::binary | std::ios::ate);
    if (!stream)
        return 0;

    const std::streampos end = stream.tellg();
    return end > 0 ? static_cast<std::uintmax_t>(end) : 0;
}

std::string library_suffix(const char* path)
{
    if (path == nullptr || *path == '\0')
        return "";

    return std::string(", ") + path + ", " + format_size(file_size(path));
}

#ifdef TINYUC_COMPARE_HAS_ICU
std::string icu_unicode_version()
{
    UVersionInfo version = {};
    u_getUnicodeVersion(version);

    std::ostringstream output;
    output << static_cast<int>(version[0]) << '.' << static_cast<int>(version[1]) << '.'
           << static_cast<int>(version[2]);
    return output.str();
}
#endif

} // namespace

std::string tinyuc_compare_info()
{
    std::vector<std::string> lines;

    lines.push_back(std::string("TinyUC ") + TINYUC_VER_STRING + " (" + TINYUC_COMPARE_BUILD_INFO +
                    library_suffix(TINYUC_COMPARE_TINYUC_LIB) + ")");

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
    lines.push_back(std::string("utf8proc ") + utf8proc_version() + " (Unicode " +
                    utf8proc_unicode_version() + library_suffix(TINYUC_COMPARE_UTF8PROC_LIB) + ")");
#endif

#ifdef TINYUC_COMPARE_HAS_ICU
    lines.push_back(std::string("ICU ") + U_ICU_VERSION + " (Unicode " + icu_unicode_version() +
                    library_suffix(TINYUC_COMPARE_ICU_LIB) + ", i18n" +
                    library_suffix(TINYUC_COMPARE_ICU_I18N_LIB)
#ifdef TINYUC_COMPARE_ICU_DATA_LIB
                    + ", data " + TINYUC_COMPARE_ICU_DATA_LIB + ", " +
                    format_size(file_size(TINYUC_COMPARE_ICU_DATA_LIB))
#endif
                    + ")");
#endif

    std::ostringstream output;
    for (std::size_t index = 0; index < lines.size(); ++index)
    {
        if (index != 0)
            output << '\n';
        output << lines[index];
    }
    return output.str();
}
