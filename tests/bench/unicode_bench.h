/**
 * @file unicode_bench.h
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Registration entry point for the unicode benchmarks.
 */

#ifndef TINYUC_TEST_UNICODE_BENCH_H
#define TINYUC_TEST_UNICODE_BENCH_H

namespace tinyuc {
namespace microbench {
class benchmark;
}
} // namespace tinyuc

void register_unicode_benchmarks(tinyuc::microbench::benchmark& bench);

#endif // TINYUC_TEST_UNICODE_BENCH_H