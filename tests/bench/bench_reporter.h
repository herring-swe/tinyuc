/**
 * @file bench_reporter.h
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Shared state for the TinyUC Catch2 benchmark reporter.
 */

#ifndef TINYUC_TESTS_BENCH_REPORTER_H
#define TINYUC_TESTS_BENCH_REPORTER_H

#include <string>

void tinyuc_bench_set_info(std::string info);

#endif // TINYUC_TESTS_BENCH_REPORTER_H
