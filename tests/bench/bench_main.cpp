/**
 * @file microbench_main.cpp
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Usage example for the internal microbench library.
 */

#include "microbench.h"
#include "unicode_bench.h"

#include <cstdint>
#include <exception>
#include <iostream>

int main(int argc, char** argv)
{
    tinyuc::microbench::benchmark bench;
    try
    {
        register_unicode_benchmarks(bench);
    }
    catch (const std::exception& error)
    {
        std::cerr << "error: " << error.what() << '\n';
        return 2;
    }

    return bench.run(argc, argv, std::cout, std::cerr);
}
