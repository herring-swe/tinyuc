/**
 * @file main_doctest.cpp
 *
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief main test function
 */

#include <tinyuc/diag.h>

#define DOCTEST_CONFIG_IMPLEMENT
TINYUC_DIAG_PUSH()
TINYUC_DIAG_IGN_NRVO()
#include <doctest.h>
TINYUC_DIAG_POP()

DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(4007) // 'function' : must be 'attribute' - see issue #182
int main(int argc, char** argv)
{
    return doctest::Context(argc, argv).run();
}
DOCTEST_MSVC_SUPPRESS_WARNING_POP
