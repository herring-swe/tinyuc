/**
 * @file bench_main.cpp
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Catch2 entry point with TinyUC benchmark reporter defaults.
 */

#include "bench_reporter.h"

#ifdef TINYUC_COMPARE
#include "compare_info.h"
#endif

#include <catch2/catch_session.hpp>
#include <catch2/internal/catch_reporter_spec_parser.hpp>

#include <cmath>

#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace {

bool parse_trim(const std::string& text, double& value)
{
    try
    {
        std::size_t consumed = 0;
        const double parsed = std::stod(text, &consumed);
        if (consumed != text.size() || !std::isfinite(parsed) || parsed < 0.0 || parsed >= 50.0)
            return false;
        value = parsed;
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
}

void add_reporter_options(std::map<std::string, std::string>& options,
                          const std::string& trim,
                          const std::string& markdown)
{
    if (!trim.empty())
        options["Xtrim"] = trim;
    if (!markdown.empty())
        options["Xmarkdown"] = markdown;
}

} // namespace

int main(int argc, char** argv)
{
    std::vector<std::string> arguments;
    std::string trim;
    std::string markdown;
    bool wants_help = false;
    bool has_order = false;

    for (int index = 1; index < argc; ++index)
    {
        if (std::string(argv[index]) == "-h" || std::string(argv[index]) == "--help")
            wants_help = true;
        if (std::string(argv[index]) == "--order" ||
            std::string(argv[index]).rfind("--order=", 0) == 0)
            has_order = true;
    }

    for (int index = 1; index < argc; ++index)
    {
        const std::string argument = argv[index];
        auto take_value = [&](const std::string& option, std::string& value) -> bool {
            if (argument == option)
            {
                if (index + 1 >= argc)
                    return false;
                value = argv[++index];
                return true;
            }
            if (argument.rfind(option + "=", 0) == 0)
            {
                value = argument.substr(option.size() + 1);
                return true;
            }
            return false;
        };

        if (argument == "--trim" || argument.rfind("--trim=", 0) == 0)
        {
            if (!take_value("--trim", trim))
            {
                std::cerr << "error: --trim requires a percentage\n";
                return 2;
            }
        }
        else if (argument == "--markdown" || argument.rfind("--markdown=", 0) == 0)
        {
            if (!take_value("--markdown", markdown) || markdown.empty())
            {
                std::cerr << "error: --markdown requires a file name\n";
                return 2;
            }
        }
        else
        {
            arguments.push_back(argument);
        }
    }

    if (!trim.empty())
    {
        double trim_percent = 0.0;
        if (!parse_trim(trim, trim_percent))
        {
            std::cerr << "error: --trim must be a percentage in [0, 50)\n";
            return 2;
        }
        (void)trim_percent;
    }

    if (!has_order)
    {
        arguments.push_back("--order");
        arguments.push_back("declared");
    }

    std::vector<const char*> child_argv;
    child_argv.push_back(argv[0]);
    for (const std::string& argument : arguments)
        child_argv.push_back(argument.c_str());

    Catch::Session session;
    const int parse_result =
        session.applyCommandLine(static_cast<int>(child_argv.size()), child_argv.data());
    if (parse_result != 0)
        return parse_result;

    std::vector<Catch::ReporterSpec>& reporters = session.configData().reporterSpecifications;
    if (reporters.empty())
    {
        std::map<std::string, std::string> options;
        add_reporter_options(options, trim, markdown);
        reporters.push_back(Catch::ReporterSpec("tinyuc", {}, {}, {}, std::move(options)));
    }
    else if (reporters.size() == 1 && reporters.front().name() == "tinyuc")
    {
        Catch::ReporterSpec reporter = reporters.front();
        std::map<std::string, std::string> options = reporter.customOptions();
        add_reporter_options(options, trim, markdown);
        reporters.front() = Catch::ReporterSpec(reporter.name(),
                                                reporter.outputFile(),
                                                reporter.colourMode(),
                                                reporter.verbosity(),
                                                std::move(options));
    }
    else if (!trim.empty() || !markdown.empty())
    {
        std::cerr << "warning: --trim and --markdown are only used by the tinyuc reporter\n";
    }

#ifdef TINYUC_COMPARE
    tinyuc_bench_set_info(tinyuc_compare_info());
#endif

    const int result = session.run();
    if (wants_help)
    {
        std::cout << "\nTinyUC benchmark options:\n"
                  << "  --trim <percent>   discard this percent from each sample tail (default 5)\n"
                  << "  --markdown <file>  also write the results as markdown tables\n";
    }

    return result;
}
